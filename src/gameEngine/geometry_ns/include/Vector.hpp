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
                Vector(const float &x = 0, const float &y = 0);
                Vector operator+(const Vector &vector) const;
                Vector operator-(const Vector &vector) const;
                Vector operator*(const Vector &vector) const;
                Vector operator/(const Vector &vector) const;
                bool operator==(const Vector &vector) const;
        };
    }
}
