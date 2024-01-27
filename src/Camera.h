// Pragma once este o directivă non-standard, dar larg acceptată,
// care asigură includerea unică a acestui fișier header.
#pragma once

// Include guards previn includerea multiplă a acestui fișier header
// într-un singur fișier de compilare.
#ifndef CAMERA_H
#define CAMERA_H

// Clasa Camera este responsabilă pentru gestionarea poziției și orientării
// camerei într-un mediu 3D.
class Camera {
public:
    // Variabile pentru reprezentarea unghiurilor camerei într-un sistem de coordonate 3D.
    // Aceste unghiuri determină direcția în care camera este orientată.
    float cameraAngleX, cameraAngleY, cameraAngleZ;

    // Variabile pentru aplicarea unor limite minimale și maxime ale mișcării camerei.
    // Aceste limite previn deplasarea camerei în afara unor anumite zone.
    float cameraMinimumX, cameraMaximumX, cameraMinumumY, cameraMaximumY, cameraMinimumZ, cameraMaximumZ;

    // Constructorul clasei Camera.
    // Inițializează unghiurile camerei și limitele de mișcare la valori implicite.
    Camera() : cameraAngleX(65.0f), cameraAngleY(10.5f), cameraAngleZ(30.0f),
        cameraMinimumX(-10.0f), cameraMaximumX(10.0f), cameraMinumumY(0.0f), cameraMaximumY(10.0f),
        cameraMinimumZ(-10.0f), cameraMaximumZ(10.0f) {}

    // Metoda updateCameraPosition este folosită pentru a actualiza poziția camerei
    // în funcție de inputul primit (de exemplu, de la tastatură).
    // @param key Codul tastei apăsate, care indică modul în care trebuie actualizată poziția camerei.
    void updateCameraPosition(int key);
};

#endif // CAMERA_H