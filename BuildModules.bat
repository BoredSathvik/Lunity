::Setup submodules
cd Nuvola/Lib/PolyHook_2_0

:: Build polyhook
cmake -B"./_build" -DCMAKE_INSTALL_PREFIX="./_install/" -DPOLYHOOK_BUILD_SHARED_LIB=OFF
cmake --build "./_build" --config Release --target INSTALL
cd ../../../
