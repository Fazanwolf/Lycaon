#pragma once

#define DEFAULT_MODE sf::VideoMode(800, 600)
#define DEFAULT_TITLE "Game"

template <typename T>
class Vector2 {
    public:
        Vector2() = default;
        ~Vector2() = default;

        Vector2(T x, T y) : x(x), y(y) {}

        Vector2<T> &operator+(const Vector2<T> &other) { return Vector2<T>(x + other.x, y + other.y); }
        Vector2<T> &operator-(const Vector2<T> &other) { return Vector2<T>(x - other.x, y - other.y); }
        Vector2<T> &operator*(const Vector2<T> &other) { return Vector2<T>(x * other.x, y * other.y); }
        Vector2<T> &operator/(const Vector2<T> &other) { return Vector2<T>(x / other.x, y / other.y); }
        Vector2<T> &operator%(const Vector2<T> &other) { return Vector2<T>(x % other.x, y % other.y); }

        T x, y;
};

typedef Vector2<unsigned int> Mode;
typedef Vector2<float> Position;
typedef Vector2<float> Scale;
typedef Vector2<int> iPosition;

template <typename T>
class Vector3 {
    public:
        Vector3() = default;
        ~Vector3() = default;

        Vector3(T x, T y, T z) : x(x), y(y), z(z) {}

        Vector3<T> &operator+(const Vector3<T> &other) { return Vector3<T>(x + other.x, y + other.y, z + other.z); }
        Vector3<T> &operator-(const Vector3<T> &other) { return Vector3<T>(x - other.x, y - other.y, z - other.z); }
        Vector3<T> &operator*(const Vector3<T> &other) { return Vector3<T>(x * other.x, y * other.y, z * other.z); }
        Vector3<T> &operator/(const Vector3<T> &other) { return Vector3<T>(x / other.x, y / other.y, z / other.z); }
        Vector3<T> &operator%(const Vector3<T> &other) { return Vector3<T>(x % other.x, y % other.y, z % other.z); }

        T x, y, z;
};

template <typename T>
class Vector4 {
    public:
        Vector4() = default;
        ~Vector4() = default;

        Vector4(T a, T b, T c, T d) : a(a), b(b), c(c), d(d) {}

        Vector4<T> &operator+(const Vector4<T> &other) { return Vector4<T>(a + other.a, b + other.b, c + other.c, d + other.d); }
        Vector4<T> &operator-(const Vector4<T> &other) { return Vector4<T>(a - other.a, b - other.b, c - other.c, d - other.d); }
        Vector4<T> &operator*(const Vector4<T> &other) { return Vector4<T>(a * other.a, b * other.b, c * other.c, d * other.d); }
        Vector4<T> &operator/(const Vector4<T> &other) { return Vector4<T>(a / other.a, b / other.b, c / other.c, d / other.d); }
        Vector4<T> &operator%(const Vector4<T> &other) { return Vector4<T>(a % other.a, b % other.b, c % other.c, d % other.d); }

        T a, b, c, d;
};

typedef Vector4<int> Rectangle;
