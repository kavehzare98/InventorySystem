#!/usr/bin/env bash
set -e

echo "[install_deps] Detecting system..."

if [ -f /etc/os-release ]; then
  . /etc/os-release
else
  echo "Cannot detect OS (no /etc/os-release)."
  exit 1
fi

case "$ID" in

  ubuntu|debian)
    echo "[install_deps] Detected Debian/Ubuntu."
    sudo apt update
    sudo apt install -y \
      g++ \
      cmake \
      make \
      qtbase5-dev
    ;;

  fedora)
    echo "[install_deps] Detected Fedora."

    # dnf5 or dnf, but we don't need groups; just install the packages directly
    if command -v dnf5 >/dev/null 2>&1; then
      echo "[install_deps] Using dnf5."
      sudo dnf5 install -y \
        gcc-c++ \
        cmake \
        make \
        qt6-qtbase-devel
    else
      echo "[install_deps] Using legacy dnf."
      sudo dnf install -y \
        gcc-c++ \
        cmake \
        make \
        qt6-qtbase-devel
    fi
    ;;

  *)
    echo "[install_deps] Unsupported distro: $ID"
    echo "Please install C++ toolchain + Qt manually."
    exit 1
    ;;
esac

echo "[install_deps] Done."

