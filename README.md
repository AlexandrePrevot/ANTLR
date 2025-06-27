how to build :
follow https://github.com/antlr/antlr4/tree/master/runtime/Cpp/cmake
based on https://tomassetti.me/getting-started-antlr-cpp/

java -jar /usr/local/lib/java/antlr-4.13.0-complete.jar -Dlanguage=Cpp -listener -visitor -o ../generated/ -package antlrcpptest ../grammar/Scene.g4
