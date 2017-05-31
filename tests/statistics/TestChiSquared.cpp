#define BOOST_TEST_MODULE "Test Chi Squared"
#define BOOST_TEST_DYN_LINK

#include <map>
#include <string>
#include <random>
#include <iostream>

#include <Eigen/Core>

#include <boost/test/unit_test.hpp>

#include <nsxlib/statistics/ChiSquared.h>

using namespace nsx;

BOOST_AUTO_TEST_CASE(Test_ChiSquared)
{
    const unsigned int num_x = 19;
    const unsigned int num_k = 14;

    const double pdf[num_k][num_x] = {{0.24197072451914337,
  0.10377687435514868,
  0.05139344326792309,
  0.026995483256594024,
  0.014644982561926487,
  0.0081086955549402422,
  0.0045533429216401758,
  0.0025833731692615079,
  0.0014772828039793361,
  0.00085003666025203336,
  0.00049157985005762186,
  0.00028546479167585544,
  0.00016635055620285914,
  9.7226505045914412e-05,
  5.6971259661427438e-05,
  3.3457556441221349e-05,
  1.9687134527509636e-05,
  1.1604420995562323e-05,
  6.8507116348430976e-06},
 {0.30326532985631671,
  0.18393972058572114,
  0.11156508007421491,
  0.067667641618306337,
  0.041042499311949393,
  0.024893534183931969,
  0.015098691711159249,
  0.0091578194443670893,
  0.005554498269121153,
  0.0033689734995427331,
  0.0020433857192320333,
  0.001239376088333179,
  0.00075171959648878618,
  0.00045594098277725807,
  0.00027654218507391676,
  0.0001677313139512559,
  0.00010173418450532208,
  6.1704902043339767e-05,
  3.7425914943850292e-05},
 {0.24197072451914337,
  0.20755374871029739,
  0.15418032980376931,
  0.10798193302637613,
  0.073224912809632448,
  0.048652173329641453,
  0.031873400451481231,
  0.020666985354092067,
  0.013295545235814032,
  0.0085003666025203432,
  0.0054073783506338362,
  0.0034255775001102579,
  0.0021625572306371659,
  0.0013611710706428008,
  0.00085456889492141117,
  0.00053532090305954125,
  0.00033468128696766353,
  0.00020887957792012197,
  0.00013016352106201906},
 {0.15163266492815836,
  0.18393972058572114,
  0.1673476201113224,
  0.1353352832366127,
  0.10260624827987348,
  0.074680602551795927,
  0.052845420989057375,
  0.036631277777468364,
  0.0249952422110452,
  0.016844867497713668,
  0.011238621455776183,
  0.0074362565299990772,
  0.0048861773771771118,
  0.0031915868794408068,
  0.0020740663880543767,
  0.0013418505116100476,
  0.00086474056829523771,
  0.00055534411839005778,
  0.00035554619196657766},
 {0.080656908173047798,
  0.1383691658068649,
  0.15418032980376928,
  0.14397591070183477,
  0.12204152134938738,
  0.097304346659282961,
  0.0743712677201228,
  0.055111960944245461,
  0.039886635707442074,
  0.028334555341734475,
  0.019827053952324078,
  0.013702310000441047,
  0.0093710813327610616,
  0.0063521316629997363,
  0.0042728444746070564,
  0.002855044816317551,
  0.0018965272928167611,
  0.0012532774675207302,
  0.00082436896672611888},
 {0.037908166232039596,
  0.091969860292860611,
  0.12551071508349182,
  0.1353352832366127,
  0.12825781034984185,
  0.11202090382769388,
  0.092479486730850408,
  0.073262555554936701,
  0.056239294974851702,
  0.042112168744284188,
  0.030906209003384519,
  0.022308769589997231,
  0.015880076475825618,
  0.011170554078042825,
  0.0077777489552039135,
  0.0053674020464401914,
  0.0036751474152547595,
  0.002499048532755259,
  0.0016888444118412433},
 {0.01613138163460956,
  0.055347666322745979,
  0.092508197882261597,
  0.11518072856146785,
  0.12204152134938738,
  0.11676521599113947,
  0.10411977480817192,
  0.088179137510792746,
  0.071795944273395765,
  0.056669110683469005,
  0.043619518695112977,
  0.032885544001058496,
  0.024364811465178746,
  0.017785968656399264,
  0.012818533423821174,
  0.0091361434122161737,
  0.0064481927955769821,
  0.0045117988830746308,
  0.0031326020735592533},
 {0.0063180277053399327,
  0.030656620097620192,
  0.062755357541745896,
  0.090223522157741778,
  0.10688150862486819,
  0.11202090382769392,
  0.10789273451932545,
  0.097683407406582212,
  0.084358942462277528,
  0.070186947907140335,
  0.056661383172871622,
  0.044617539179994482,
  0.03440683236428884,
  0.026064626182099898,
  0.019444372388009768,
  0.014313072123840496,
  0.010412917676555168,
  0.0074971455982657731,
  0.0053480073041639389},
 {0.002304483090658508,
  0.015813618949355977,
  0.039646370520969247,
  0.065817559177981599,
  0.087172515249562418,
  0.10008447084954815,
  0.10411977480817192,
  0.10077615715519164,
  0.092309071208651672,
  0.080955872404955651,
  0.068544957949463178,
  0.056375218287528818,
  0.045248935578189119,
  0.0355719373127985,
  0.027468285908188214,
  0.020882613513636954,
  0.015659896789258398,
  0.011601768556477609,
  0.0085027770568036776},
 {0.00078975346316749137,
  0.0076641550244050498,
  0.023533259078154713,
  0.045111761078870882,
  0.0668009428905426,
  0.084015677870770383,
  0.094406142704409751,
  0.097683407406582212,
  0.094903810270062255,
  0.087733684883925411,
  0.077909401862698471,
  0.066926308769991685,
  0.055911102591969325,
  0.045613095818674822,
  0.036458198227518321,
  0.028626144247680996,
  0.022127450062679709,
  0.016868577596097997,
  0.012701517347389349},
 {0.00025605367673983405,
  0.0035141375443013298,
  0.013215456840323072,
  0.029252248523547377,
  0.048429175138645739,
  0.066722980566365386,
  0.080982047073022603,
  0.089578806360170266,
  0.09230907120865163,
  0.089950969338839698,
  0.083777170827121814,
  0.075166957716705174,
  0.065359573612939786,
  0.055334124708797672,
  0.045780476513647035,
  0.037124646246465706,
  0.029579805046376945,
  0.023203537112955228,
  0.017950307119918893},
{ 7.8975346316749185e-05,
  0.0015328310048810111,
  0.0070599777234464211,
  0.018044704431548368,
  0.033400471445271328,
  0.05040940672246224,
  0.066084299893086826,
  0.078146725925265836,
  0.085413429243056144,
  0.087733684883925578,
  0.085700342048968384,
  0.080311570523990045,
  0.072684433369560139,
  0.063858334146144807,
  0.054687297341277544,
  0.04580183079628964,
  0.037616665106555501,
  0.030363439672976437,
  0.0241328829600397750},
 {2.3277606976348588e-05,
  0.00063893409896387872,
  0.0036042155019062995,
  0.010637181281289971,
  0.022013261426657185,
  0.036394353036199326,
  0.051534029955559904,
  0.065148222807396655,
  0.075525603716169648,
  0.081773608489854321,
  0.083777170827121772,
  0.082000317509132989,
  0.077243132451656177,
  0.070425249629378961,
  0.062427922518609694,
  0.053999485449404742,
  0.04571424416258265,
  0.037969424366654014,
  0.031005075934405348},
 {6.58127885972909e-06,
  0.00025547183414683489,
  0.0017649944308616033,
  0.0060149014771827825,
  0.013916863102196369,
  0.025204703361231137,
  0.038549174937633969,
  0.052097817283510456,
  0.064060071932292004,
  0.073111404069937894,
  0.078558646878220992,
  0.080311570523990114,
  0.078741469483690221,
  0.074501389837168794,
  0.068359121676596801,
  0.061069107728386071,
  0.053290275567620407,
  0.0455451595094645,
  0.038210398020062951}};

  const double cdf[num_k][num_x] = {{
  0.68268949213708585,
  0.84270079294971512,
  0.91673548333644961,
  0.95449973610364147,
  0.97465268132253169,
  0.98569412156457037,
  0.99184902840649725,
  0.99532226501895271,
  0.99730020393673979,
  0.9984345977419975,
  0.99908888112284633,
  0.99946799449486079,
  0.99968850902323259,
  0.99981718936701813,
  0.99989248882327053,
  0.99993665751633376,
  0.99996262018159832,
  0.99997790950300136,
  0.99998692815463319},
 {0.39346934028736652,
  0.63212055882855767,
  0.77686983985157021,
  0.8646647167633873,
  0.91791500137610116,
  0.95021293163213605,
  0.96980261657768152,
  0.98168436111126578,
  0.98889100346175773,
  0.99326205300091452,
  0.99591322856153597,
  0.99752124782333362,
  0.99849656080702243,
  0.99908811803444553,
  0.99944691562985222,
  0.99966453737209748,
  0.99979653163098936,
  0.99987659019591335,
  0.99992514817011235},
 {0.19874804309879915,
  0.42759329552912023,
  0.60837482372891094,
  0.73853587005088883,
  0.82820285570326646,
  0.88838977490528737,
  0.92810222750353488,
  0.95398829431076859,
  0.97070911346511179,
  0.9814338645369568,
  0.98827412442157858,
  0.99261683949464019,
  0.99536339456195833,
  0.99709484722573261,
  0.9981833510334277,
  0.99886601571021472,
  0.99929325760766297,
  0.99956015034716117,
  0.99972660111250922},
 {0.090204010431049864,
  0.26424111765711528,
  0.44217459962892519,
  0.59399415029016156,
  0.71270250481635422,
  0.80085172652854419,
  0.86411177459956678,
  0.90842180555632912,
  0.93890051903966731,
  0.95957231800548726,
  0.97343598564998357,
  0.98264873476333547,
  0.9887242060526682,
  0.99270494427556388,
  0.9952987828537434,
  0.99698083634887735,
  0.99806705049439892,
  0.99876590195913317,
  0.99921405578617917},
 {0.037434226752703609,
  0.15085496391539038,
  0.30001416412137238,
  0.45058404864721979,
  0.58411981300449201,
  0.69378108158672125,
  0.77935969206328937,
  0.84376437242227786,
  0.89093584205022747,
  0.92476475385348778,
  0.94862001651693051,
  0.96521221949375813,
  0.97662123189643624,
  0.98439058389973311,
  0.98963766208421355,
  0.99315592607757952,
  0.99550020302202946,
  0.99705359541211969,
  0.998077863179057},
 {0.014387677966970684,
  0.080301397071394179,
  0.19115316946194183,
  0.32332358381693654,
  0.45618688411667035,
  0.57680991887315658,
  0.6791528011378658,
  0.76189669444645558,
  0.82642192908996392,
  0.87534798051691887,
  0.91162356764321451,
  0.93803119558334103,
  0.95696405310101695,
  0.97036383611947818,
  0.97974328494333562,
  0.98624603225599705,
  0.99071675566388939,
  0.99376780489362271,
  0.99583636696249667},
 {0.0051714634834845175,
  0.040159631269898431,
  0.11499776835684938,
  0.22022259152428406,
  0.34003677030571755,
  0.4602506496044429,
  0.57112014244694542,
  0.6674060974006919,
  0.74734395350343608,
  0.81142653248655006,
  0.86138097912670442,
  0.89944113149164118,
  0.9278916089660787,
  0.9488186465869346,
  0.96400059523657122,
  0.97488363925314725,
  0.98260381743087555,
  0.98802999764597044,
  0.99181265903193849},
 {0.0017516225562908239,
  0.018988156876153808,
  0.06564245437845008,
  0.14287653950145296,
  0.2424238668669339,
  0.35276811121776874,
  0.46336733209921499,
  0.56652987963329104,
  0.65770404416540895,
  0.73497408470263847,
  0.79830080129747127,
  0.84879611722335213,
  0.88815038837243943,
  0.91823458375527844,
  0.94085454016731607,
  0.95761988800831599,
  0.96989092031077906,
  0.97877351369709109,
  0.98514035235416875},
 {0.00056249730216750154,
  0.0085323933711864662,
  0.035705027314910875,
  0.088587473168320829,
  0.16569173980659252,
  0.26008170790534624,
  0.36288059283060159,
  0.4658537830903085,
  0.56272581108613307,
  0.64951478767663873,
  0.72429106322777803,
  0.7866906949165835,
  0.8373937378097005,
  0.87767477196133747,
  0.90906402342019488,
  0.93311841222587333,
  0.95128402385235866,
  0.96482646053301524,
  0.974807104918331},
 {0.00017211562995584072,
  0.0036598468273437131,
  0.018575936222140675,
  0.052653017343711125,
  0.10882198108584877,
  0.18473675547622787,
  0.27455504669039571,
  0.37116306482012662,
  0.46789642362528489,
  0.55950671493478787,
  0.64248199757207458,
  0.71494349968336879,
  0.7763281831885005,
  0.82700839211792854,
  0.8679381437122794,
  0.90036759951295409,
  0.92563602018541957,
  0.94503635850489498,
  0.95973731765939008},
 {5.0389948687833127e-05,
  0.0015041182825838032,
  0.0092741136342647124,
  0.030082976121226047,
  0.068833389529300848,
  0.12663574677261547,
  0.20091649868455616,
  0.28669617036996786,
  0.37810766866882956,
  0.4696128489989595,
  0.55673672157353482,
  0.63635677948317326,
  0.70667459058382076,
  0.76700652254374213,
  0.8175030703929006,
  0.858869119732942,
  0.89212441375960494,
  0.91841938630710462,
  0.9389064906784933},
 {1.4164937322342495e-05,
  0.00059418481758169298,
  0.0044559807752478494,
  0.016563608480614431,
  0.042021038195306143,
  0.083917942031303469,
  0.14238644690422175,
  0.21486961296959481,
  0.29706956513917254,
  0.384039345166937,
  0.47108131347413745,
  0.55432035863538853,
  0.6309593164493803,
  0.69929172382563909,
  0.75856354902972456,
  0.80876393792037471,
  0.85040268997230861,
  0.8843094791589422,
  0.91147155173931027},
 {3.8347347351359549e-06,
  0.00022625008465604722,
  0.0020656826304521242,
  0.0088086135586461344,
  0.024806866675986548,
  0.053847040700216849,
  0.097848438773436436,
  0.15639972475517447,
  0.22705646123649048,
  0.30606563201925102,
  0.38918237991929117,
  0.47235614446490742,
  0.55218832568050824,
  0.62615602328498443,
  0.69264722535568168,
  0.7508701488341325,
  0.80069592543443968,
  0.84248053757379671,
  0.87689633880968221},
 {1.0023796028842995e-06,
  8.3241149288023104e-05,
  0.00092599191352464268,
  0.0045338055262488649,
  0.014187311990913347,
  0.033508535308841216,
  0.065288097028953704,
  0.11067397840257361,
  0.16894942127458848,
  0.23781653702706129,
  0.31396401971769611,
  0.39369721758740861,
  0.47347637748200028,
  0.55028894415130081,
  0.62184530567653062,
  0.68662572246360232,
  0.74382213883706827,
  0.79321916014001292,
  0.83505075569918441
  }};

  for (int k = 1; k <= num_k; ++k) {
      nsx::ChiSquared chi2(k);

      BOOST_CHECK_SMALL(chi2.cdf(0.0), 1e-10);
      BOOST_CHECK_CLOSE(chi2.cdf(200.0), 1.0, 1e-10);

      for (int x = 1; x <= num_x; ++x) {
          std::cout << k << "     " << x << std::endl;
          BOOST_CHECK_CLOSE(chi2.cdf(x), cdf[k-1][x-1], 1e-5);
          BOOST_CHECK_CLOSE(chi2.pdf(x), pdf[k-1][x-1], 1e-5);
      }
  }

}
