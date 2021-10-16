:: Setup classbuilder to generate the bridge source code
cd ClassBuilder
cmake .
cmake --build . --config Release
cd Release
ClassBuilder.exe --proj "../../Nuvola/Client/Bridge/bridge.json" --gen CppGen --output "../../Nuvola/Client/Bridge/"
cd ../../
