cmake_minimum_required(VERSION 3.21)
project(InventoryApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Let CMake run moc/uic/rcc automatically for Qt classes
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

# ---------- core library ----------
add_library(inventory_core
  core/Inventory.cpp
)

target_include_directories(inventory_core
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/core
)

# For the future: if Inventory.cpp uses other libs such as a sql database, link it here.
# target_link_libraries(inventory_core PUBLIC sqlite3)

# ---------- GUI executable ----------
add_executable(inventory_gui
  gui/MainWindow.h
  gui/MainWindow.cpp
  gui/gui_main.cpp
)

target_include_directories(inventory_gui
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/gui
    ${CMAKE_CURRENT_SOURCE_DIR}/core
)

target_link_libraries(inventory_gui
  PRIVATE
    inventory_core
    Qt5::Widgets
)

# ---------- CLI executable (old main, optional) ----------
add_executable(inventory_cli
  cli/main.cpp
)

target_include_directories(inventory_cli
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/core
)

target_link_libraries(inventory_cli
  PRIVATE inventory_core
)

