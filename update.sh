#!/bin/bash

# Detect OS from /etc/os-release
version=$(grep '^ID=' /etc/os-release | cut -d'=' -f2 | tr -d '"')

echo "Detected OS: $version"


# Debian-based systems
if [[ "$version" == "debian" || "$version" == "ubuntu" || "$version" == "kali" || "$version" == "pop" ]]; then
    echo "Updating system for Debian-based OS ($version)..."
    sudo apt-get update
    read -p "Do you also want to upgrade? (Y/N): " upg
    if [[ "$upg" == "y" || "$upg" == "Y" ]]; then
        echo "Upgrading... This may take some time."
        sudo apt-get upgrade -y
    else
        echo "Upgrade skipped."
    fi
    
# Red Hat-based systems
elif [[ "$version" == "centos" || "$version" == "fedora" || "$version" == "rhel" || "$version" == "rocky" ]]; then
    echo "Updating system for Red Hat-based OS ($version)..."
    if command -v dnf &>/dev/null; then
        sudo dnf update -y
    else
        sudo yum update -y
    fi
           
# Arch-based systems
elif [[ "$version" == "arch" || "$version" == "manjaro" ]]; then
    echo "Updating system for Arch-based OS ($version)..."
    sudo pacman -Syu --noconfirm

# macOS
elif [[ "$version" == "macos" ]]; then
    echo "Updating system for macOS..."
    brew update && brew upgrade
# Unsupported OS
else
    echo "❌ OS not supported for updates!"
    exit 1
fi

echo "✅ Update process completed successfully!"
          
 
