project(Battle_City)

set (SOURCE Core.cpp Map.cpp Tank.cpp Shell.cpp Player.cpp Enemy.cpp ShellsController.cpp EnemiesController.cpp GameOver.cpp)

add_executable(game ${SOURCE})

target_include_directories(game PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Headers)
target_link_libraries(game sfml-graphics sfml-window sfml-system sfml-audio)
