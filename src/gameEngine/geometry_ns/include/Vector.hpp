/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Vector
*/


namespace gameEngine_ns {
    namespace geometry_ns {
        class Vector {
            private:
                float _x;
                float _y;
            public:
                Vector(const float &x, const float &y);
                Vector &get() const;
                void setX(const float &x);
                void setY(const float &y);
                void set(const float &x, const float &y);
                void set(const Vector &vector);
        };
    }
}
