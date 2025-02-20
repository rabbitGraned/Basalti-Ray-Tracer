# Basalti Ray Tracer

<div align="center">
  <img src="https://github.com/user-attachments/assets/c4ed9749-9690-46f6-9790-4d3f10b927eb" alt="image" width="50%">
</div>

$$(x−cx​)2+(y−cy​)2+(z−cz​)2=r2$$

<div align="center">
  <p>Example Shpere</p>
</div>


## About
The program is a simple path tracer that allows rendering basic primitives: `sphere`, `cube`, and `cylinder`. The program provides the option to select an object for rendering through a console menu. Visualization occurs in the background, and the rendering result is saved in a `.ppm` file.

## Build
1. The following is required:
   
   A compiler no lower than C++17.
    
2. Clone the repository or download the source code.
    
3. Compile the program using the command:
    
    bash
    `g++ -o Basalti\ Ray\ Tracer "Basalti Ray Tracer.cpp" Tracer.cpp Ray.cpp Vec3.cpp Sphere.cpp Cube.cpp Cylinder.cpp -std=c++17`
    
4. Run the compiled program:
    
    bash
    `./Basalti\ Ray\ Tracer`
    cmd
    `Basalti Ray Tracer.exe`
    
Or similar actions within Visual Studio (project startup files are already in the source).

## Usage
Select the appropriate primitive by the specified number.

After selecting an object, the program will perform rendering and save the result in the `image.ppm` file.

## Parameter Configuration
In the file `Basalti Ray Tracer.cpp`, you can change the following parameters:
- **Image Resolution** :
    
    `int width = 1920, height = 1080;`
    
- **Camera Position** :
    
    `Vec3 cameraPos(0, 0, -5);`
    
By default, the camera looks straight at the object.
    
- **Light Source Position** :
    
    `Vec3 lightPos(5, 4, -5);`

## Output File Format
The program saves the rendering result in the `image.ppm` file in Portable Pixmap (PPM) format. To view the result, open the `image.ppm` file in any compatible application.

## License
This project is distributed under the MIT license. For details, see the `LICENSE` file.
This implementation is a very simple ray tracer that allows understanding the principles of scene construction based on ray tracing, working with vector coordinates, and describing some primitives.

## Links
«Basalti» by rabbitGraned.

[rabbitGraned Animation](https://t.me/rabbitGranedAnimation)
