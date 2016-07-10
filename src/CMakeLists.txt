set(GAME_SOURCES main.cpp matrix.cpp matrixmodel.cpp)

qt5_add_resources(RESOURCES qml.qrc)

add_executable(2048 ${GAME_SOURCES} ${RESOURCES})

target_link_libraries(2048 PUBLIC
    Qt5::Core
    Qt5::Quick
)

install(TARGETS 2048 DESTINATION bin)

