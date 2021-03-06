// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      tests/chemistry/TestMCAbsorption.cpp
//! @brief     Implements module/class/test TestMCAbsorption
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <memory>

#include <Eigen/Dense>

#include <nsxlib/ChemistryTypes.h>
#include <nsxlib/ConvexHull.h>
#include <nsxlib/Material.h>
#include <nsxlib/MCAbsorption.h>
#include <nsxlib/NSXTest.h>
#include <nsxlib/Units.h>

NSX_INIT_TEST

int main()
{
    // Build an isotopically pure methane material
    std::unique_ptr<nsx::Material> helium(new nsx::Material("He[3]"));

    // Create a cubic convex hull
    nsx::ConvexHull chull;
    chull.addVertex(Eigen::Vector3d( 0, 0, 0));
    chull.addVertex(Eigen::Vector3d( 1, 0, 0));
    chull.addVertex(Eigen::Vector3d( 0, 1, 0));
    chull.addVertex(Eigen::Vector3d( 0, 0, 1));
    chull.addVertex(Eigen::Vector3d( 1, 1, 0));
    chull.addVertex(Eigen::Vector3d( 1, 0, 1));
    chull.addVertex(Eigen::Vector3d( 0, 1, 1));
    chull.addVertex(Eigen::Vector3d( 1, 1, 1));
    chull.updateHull();
    chull.translateToCenter();
    chull.scale(0.032);

    double muScattering = helium->muIncoherent();
    double muAbsorption = helium->muAbsorption(1.46e-10);

    // Create the MC absorption calculator
    nsx::MCAbsorption mca(chull,3.2*nsx::cm,3.2*nsx::cm,-100);
    mca.setMuScattering(muScattering);
    mca.setMuAbsorption(muAbsorption);

    // Compute the transmission factor
    mca.run(10,Eigen::Vector3d(0,1,0),Eigen::Matrix3d::Identity());

    // Build an isotopically pure methane material
    std::unique_ptr<nsx::Material> methane(new nsx::Material("CH4"));
    double mm = methane->molarMass();
    double volume = chull.volume();
    methane->setMassDensity(mm/volume);

    // Create the MC absorption calculator
    mca = nsx::MCAbsorption(chull,3.2*nsx::cm,3.2*nsx::cm,-100);

    muScattering = methane->muIncoherent();
    muAbsorption = methane->muAbsorption(1.46e-10);

    // Set the material scattering and absorption attenuation factors
    mca.setMuScattering(muScattering);
    mca.setMuAbsorption(muAbsorption);

    // Compute the transmission factor
    mca.run(10000,Eigen::Vector3d(0,1,0),Eigen::Matrix3d::Identity());

    return 0;
}
