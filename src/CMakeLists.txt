set(GAME_SOURCES main.cpp )

qt5_add_resources(RESOURCES qmlFile.qrc)

add_executable(binary ${GAME_SOURCES} ${RESOURCES})

target_link_libraries(binary PUBLIC
    Qt5::Core
    Qt5::Quick
)
