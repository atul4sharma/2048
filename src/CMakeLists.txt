set(GAME_SOURCES main.cpp matrix.cpp matrixmodel.cpp)

qt5_add_resources(RESOURCES qml.qrc)

add_executable(GAME ${GAME_SOURCES} ${RESOURCES})

target_link_libraries(GAME PUBLIC
    Qt5::Core
    Qt5::Quick
)
