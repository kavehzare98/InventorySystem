# InventorySystem
Inventory System application now supports CLI and GUI on Fedora & Ubuntu Linux.

## Command Line Interface (CLI)
![Command Line Interface (CLI)](https://github.com/kavehzare98/InventorySystem/blob/main/assets/cli.png)

## Graphical User Interface (GUI)
![Graphical User Interface (GUI)](https://github.com/kavehzare98/InventorySystem/blob/main/assets/gui.png)

## Steps to Install
```bash
git clone
cd InventorySystem
```

### 1. Install all dependencies (compiler, Qt, CMake)
```bash
./scripts/1_install_dependencies.sh
```
#### 1.1 Input your password installation to complete successfully

### 2. Configure build directory
```bash
./scripts/2_configure.sh
```

### 3. Build GUI and CLI
```bash
./scripts/3_build.sh
```

## Run GUI
```bash
./scripts/last_run_gui.sh
```

## Run CLI
```bash
./scripts/last_run_cli.sh
```

