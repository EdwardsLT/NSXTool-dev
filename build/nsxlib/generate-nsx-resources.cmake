execute_process(COMMAND /usr/bin/cmake -E copy /home/lewisedwards/bin/nsxtool-dev/build/nsxlib/tmp/Resources.cpp /home/lewisedwards/bin/nsxtool-dev/build/nsxlib/generated/Resources.cpp)
  foreach (NSX_RESOURCE /home/lewisedwards/bin/nsxtool-dev/resources/databases/Isotopes.yml;/home/lewisedwards/bin/nsxtool-dev/resources/instruments/BioDiff2500.yml;/home/lewisedwards/bin/nsxtool-dev/resources/instruments/BioDiff5000.yml;/home/lewisedwards/bin/nsxtool-dev/resources/instruments/D10.yml;/home/lewisedwards/bin/nsxtool-dev/resources/instruments/D19.yml;/home/lewisedwards/bin/nsxtool-dev/resources/instruments/D9.yml;/home/lewisedwards/bin/nsxtool-dev/resources/instruments/D9_large.yml;/home/lewisedwards/bin/nsxtool-dev/resources/instruments/D9_large_lifting_arm.yml;/home/lewisedwards/bin/nsxtool-dev/resources/instruments/D9_lifting_arm.yml;/home/lewisedwards/bin/nsxtool-dev/resources/instruments/I16.yml)
    get_filename_component(NSX_RESOURCE_NAME ${NSX_RESOURCE} NAME_WE)
    get_filename_component(NSX_RESOURCE_DIR ${NSX_RESOURCE} DIRECTORY)
    get_filename_component(NSX_RESOURCE_TYPE ${NSX_RESOURCE_DIR} NAME)

    execute_process(COMMAND /home/lewisedwards/bin/nsxtool-dev/build/nsxlib/update_resources ${NSX_RESOURCE_TYPE} ${NSX_RESOURCE_NAME} /home/lewisedwards/bin/nsxtool-dev/build/nsxlib/generated/Resources.cpp)
  endforeach ()