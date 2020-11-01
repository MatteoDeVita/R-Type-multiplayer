/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Vector
*/


namespace gameEngine_ns {
    namespace geometry_ns {
        class Vector {
            
            public:
                float x;
                float y;
                Vector(const float &x, const float &y);
                Vector operator+(const Vector &vector);
                Vector operator-(const Vector &vector);
                Vector operator*(const Vector &vector);
                Vector operator/(const Vector &vector);
                bool operator==(const Vector &vector);
        };
    }
}
