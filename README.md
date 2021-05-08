# nao_description
DO NOT MAKE THIS PUBLIC, IT CONFLICTS WITH SOFTWARE LICENSING. urdf model of robot

## Setup

To install the 3d model meshes for the NAO,

    wget https://github.com/ros-naoqi/nao_meshes_installer/raw/master/naomeshes-0.6.7-linux-x64-installer.run
    chmod +x naomeshes-0.6.7-linux-x64-installer.run
    ./naomeshes-0.6.7-linux-x64-installer.run

From the generated folder, 
* copy meshes/V40 directory to meshes/V40 directory in this project
* copy texture/ directory to texture directory in this project

## Running

To visualise the urdf robot in rviz, run

`ros2 launch nao_description everything_launch.py`
