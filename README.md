# nao_description

## Setup

To install the 3d model meshes for the NAO,

    wget https://github.com/ros-naoqi/nao_meshes_installer/raw/master/naomeshes-0.6.7-linux-x64-installer.run
    chmod +x naomeshes-0.6.7-linux-x64-installer.run
    ./naomeshes-0.6.7-linux-x64-installer.run

**Copy meshes/ and texture/ directory into this package's root directory.**

## Running

To visualise the urdf robot in rviz, run

`ros2 launch nao_description everything_launch.py`
