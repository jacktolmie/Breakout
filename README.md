A basic Breakout game that was in the Advanced C++ course on Udemy.
I modified almost all of the code, so this is almost nothing like the actual one from the course. 
Implemented:
<ul>
    <li>Text box on top to display lives/level.</li>
    <li>Row of bricks change depending on the level.</li>
    <li>Random stronger bricks are added as level increases.</li>
    <li>Added additional colours of bricks according to strength of the brick (red/blue/green).</li>
    <li>Speed of ball changes as level increases.</li>
    <li>Added additional spin etc to the paddle/ball connection to adjust the trajectory of the ball if paddle is moving when the ball hits it.</li>
    <li>Increase paddle size if increase_paddle sprite is hit.</li>
    <li>Split the Game class into multiple .cpp files.</li>
    <li>Various other changes.</li>
</ul>


### Breakout template

This template is packaged using CMake.
To install it you can run:  
```bash
mkdir -p build
cd build
cmake ..
cmake --build . --target install
```

After this the template shows up in the dialog under File -> New From Template.

You can also do this graphically using KDevelop:  
![KDevelop Tools](kdevelop_tools.png)

If you think that the template can be useful to other people,
consider uploading it to the KDE store https://store.kde.org/browse/cat/327/.

In case you have an older version of the KDE Frameworks(<5.77)
you have to delete the old tar to make sure it gets recreated.
This can be done using the clean button in KDevelop
(on the right of the "Install Selection" button in the screenshot)
or by running this command in the build directory:
```bash
cmake --build . --target clean
```

It you want to create multiple templates you can add new directories to the root
of this project and add them to the template package macro:  
```cmake
kde_package_app_templates(TEMPLATES "Breakout" "mysecondtemplate" INSTALL_DIR ...)
```

