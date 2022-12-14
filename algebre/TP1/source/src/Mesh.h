#ifndef MESH_H
#define MESH_H

#include"Triangle.h"
#include "Vec3.h"
#include <vector>

struct Mesh {
    std::vector <Vec3> vertices; //array of mesh vertices positions
    std::vector <Vec3> normals; //array of vertices normals useful for the display
    std::vector <Triangle> triangles; //array of mesh triangles
    std::vector <Vec3> triangle_normals; //triangle normals to display face normals

    //Compute face normals for the display
    void computeTrianglesNormals() {
        // Vider le vecteur triangle_normals (i.e. faire un clear du vecteur)
        triangle_normals.clear();

        //TODO: implémenter le calcul des normales par face
        //Iterer sur les triangles du maillage
        for (int i = 0; i <= 2; i++) {

            //La normale du triangle i est le resultat du produit vectoriel de deux ses arêtes e_10 et e_20 normalisé (e_10^e_20)
            //L'arete e_10 est représentée par le vecteur partant du sommet 0 (triangles[i][0]) au sommet 1 (triangles[i][1])
            //L'arete e_20 est représentée par le vecteur partant du sommet 0 (triangles[i][0]) au sommet 2 (triangles[i][2])
        Vec3 e_10 = vertices[triangles[i][0] - triangles[i][1]];
        Vec3 e_20 = vertices[triangles[i][0] - triangles[i][2]];
            //Normaliser le resultat, utiliser la fonction normalize()
        Vec3 n (Vec3::cross(e_10, e_20));
        n.normalize ();
            //Ajouter dans triangle_normales
        triangle_normals.push_back (n);
        }   

    }

    //Compute vertices normals as the average of its incident faces normals
    void computeVerticesNormals() {
        // Vider le vecteur normals (i.e. faire un clear du vecteur)
        normals.clear();
        //TODO: implémenter le calcul des normales par sommet comme la moyenne des normales des triangles incidents
        //Initialiser le vecteur normals taille vertices.size() avec Vec3(0., 0., 0.)
        Vec3(0.,0.,0.);
        Vec3 vertices.size() = Vec3(0.,0.,0.);
        //Iterer sur les triangles
        /*for(int i=0; i<=triangles.size(); i++){
            
        }*/
            //Pour chaque triangle i
            //Ajouter la normal au triangle à celle de chacun des sommets

        //Iterer sur les normales et les normaliser

    }

    void computeNormals() {
        computeTrianglesNormals();
        computeVerticesNormals();
    }

    Mesh(){}

    Mesh( Mesh const& i_mesh):
        vertices(i_mesh.vertices),
        normals(i_mesh.normals),
        triangles(i_mesh.triangles),
        triangle_normals(i_mesh.triangle_normals)
    {}

    Mesh( std::vector <Vec3> const& i_vertices, std::vector <Triangle> const& i_triangles):
        vertices(i_vertices),
        triangles(i_triangles)
    {
        computeNormals();
    }

};


#endif // MESH_H
