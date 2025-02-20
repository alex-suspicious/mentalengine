


namespace amath{
    float r2d = 180.0f/3.14159265f;
    float delta = 0.0001f;
    static const auto L_PI = acos( -1 );
    auto PIH = amath::L_PI/2.0f;

    float clip(float n, float lower, float upper) {
        return std::max(lower, std::min(n, upper));
    }

    float sqrf( float value )
    {
        return value * value;
    }

    float lerp(float a, float b, float t)
    {
        return a + t * (b - a);
    }

    class Vector2;

    class Vector3{
        public: 
            float x;
            float y;
            float z;

        Vector3(){
            this->x = 0;
            this->y = 0;
            this->z = 0;
        }

        Vector3( float x, float y, float z ){
            this->x = x;
            this->y = y;
            this->z = z;
        }

        Vector3 xxx() const;
        Vector3 xxy() const;
        Vector3 xxz() const;
        Vector3 xyx() const;
        Vector3 xyy() const;
        Vector3 xyz() const;
        Vector3 xzx() const;
        Vector3 xzy() const;
        Vector3 xzz() const;
        Vector3 yxx() const;
        Vector3 yxy() const;
        Vector3 yxz() const;
        Vector3 yyx() const;
        Vector3 yyy() const;
        Vector3 yyz() const;
        Vector3 yzx() const;
        Vector3 yzy() const;
        Vector3 yzz() const;
        Vector3 zxx() const;
        Vector3 zxy() const;
        Vector3 zxz() const;
        Vector3 zyx() const;
        Vector3 zyy() const;
        Vector3 zyz() const;
        Vector3 zzx() const;
        Vector3 zzy() const;
        Vector3 zzz() const;
        Vector2 xx() const;
        Vector2 xy() const;
        Vector2 xz() const;
        Vector2 yy() const;
        Vector2 yx() const;
        Vector2 yz() const;
        Vector2 zz() const;
        Vector2 zx() const;
        Vector2 zy() const;

        Vector3 operator+( Vector3 B )
        {
            return Vector3( this->x + B.x, this->y + B.y, this->z + B.z );
        }

        Vector3 operator-( Vector3 B )
        {
            return Vector3( this->x - B.x, this->y - B.y, this->z - B.z );
        }

        Vector3 operator*( Vector3 B )
        {
            return Vector3( this->x * B.x, this->y * B.y, this->z * B.z );
        }

        Vector3 operator/( Vector3 B )
        {
            return Vector3( this->x / B.x, this->y / B.y, this->z / B.z );
        }

        Vector3 operator+( float B )
        {
            return Vector3( this->x + B, this->y + B, this->z + B );
        }

        Vector3 operator-( float B )
        {
            return Vector3( this->x - B, this->y - B, this->z - B );
        }

        Vector3 operator*( float B )
        {
            return Vector3( this->x * B, this->y * B, this->z * B );
        }

        Vector3 operator/( float B )
        {
            return Vector3( this->x / B, this->y / B, this->z / B );
        }

        std::string toString(){
            return "{ x: " + std::to_string(this->x) + ", y: " + std::to_string(this->y) + ", z: " + std::to_string(this->z) + " }";
        }

        ::Vector3 raylib(){
            return ::Vector3{this->x,this->y,this->z};
        }
    };

    class Vector2{
        public: 
            float x;
            float y;

        Vector2(){
            this->x = 0;
            this->y = 0;
        }

        Vector2( ::Vector2 B ){
            this->x = B.x;
            this->y = B.y;
        }

        Vector2( ::Vector3 B ){
            this->x = B.x;
            this->y = B.y;
        }

        Vector2( float x, float y ){
            this->x = x;
            this->y = y;
        }

        Vector3 xxx() const;
        Vector3 xxy() const;
        Vector3 xyx() const;
        Vector3 xyy() const;
        Vector3 yxx() const;
        Vector3 yxy() const;
        Vector3 yyx() const;
        Vector3 yyy() const;
        Vector2 xx() const;
        Vector2 xy() const;
        Vector2 yy() const;
        Vector2 yx() const;

        Vector2 operator+( Vector2 B )
        {
            return Vector2( this->x + B.x, this->y + B.y );
        }

        Vector2 operator-( Vector2 B )
        {
            return Vector2( this->x - B.x, this->y - B.y );
        }

        Vector2 operator*( Vector2 B )
        {
            return Vector2( this->x * B.x, this->y * B.y );
        }

        Vector2 operator/( Vector2 B )
        {
            return Vector2( this->x / B.x, this->y / B.y );
        }

        Vector2 operator+( float B )
        {
            return Vector2( this->x + B, this->y + B );
        }

        Vector2 operator-( float B )
        {
            return Vector2( this->x - B, this->y - B );
        }

        Vector2 operator*( float B )
        {
            return Vector2( this->x * B, this->y * B );
        }

        Vector2 operator/( float B )
        {
            return Vector2( this->x / B, this->y / B );
        }

        float length(){
            return sqrt( amath::sqrf( this->x ) + amath::sqrf( this->y ) );
        }

        Vector2 lerp( Vector2 B, float amount ){
            return Vector2( amath::lerp(this->x, B.x, amount), amath::lerp(this->y, B.y, amount) );
        }

        float angle(){
            return atan2(this->y,this->x) * (180 / L_PI);
        }

        float radians(){
            return atan2(this->y,this->x);
        }

        Vector2 normalize(){
            float length = this->length();
            return Vector2( this->x / length, this->y / length);
        }

        Vector2 align(){
            return std::abs(this->x) > std::abs(this->y) ? Vector2( this->x, 0) : Vector2( 0, this->y);
        }

        Vector2 reflect( Vector2 normal ) {
            float dotProduct = this->x * normal.x + this->y * normal.y;

            float reflectionX = this->x - 2 * dotProduct * normal.x;
            float reflectionY = this->y - 2 * dotProduct * normal.y;

            return Vector2(reflectionX, reflectionY);
        }

        float distance( Vector2 b ) {
            return std::sqrt( std::pow( (b.x - this->x), 2) + std::pow((b.y - this->y), 2) );
        }

        std::string toString(){
            return "{ x: " + std::to_string(this->x) + ", y: " + std::to_string(this->y) + " }";
        }

        ::Vector2 raylib(){
            return ::Vector2{this->x,this->y};
        }

        ::Vector3 raylib3D(){
            return ::Vector3{this->x,this->y,0.0f};
        }

        Vector2 right(){
            float radians = atan2( this->y, this->x ) + amath::PIH;
            return Vector2( cos(radians), sin(radians) );
        }

        Vector2 left(){
            float radians = atan2( this->y, this->x ) - amath::PIH;
            return Vector2( cos(radians), sin(radians) );
        }

        Vector2 forward(){
            return Vector2(this->x, this->y);
        }

        Vector2 backward(){
            float radians = atan2( this->y, this->x ) + amath::L_PI;
            return Vector2( cos(radians), sin(radians) );
        }

        Vector2 rotate( float angle ){
            float radians = atan2( this->y, this->x ) + angle;
            return Vector2( cos(radians), sin(radians) );
        }

    };


    class Angle {
        public:
            double value;

        Angle(){
            this->value = 0;
        }

        Angle( double newValue ){
            this->value = newValue;
        }

        Angle radians(){
            this->value = ( this->value / 180.0f ) * amath::L_PI;
            return *this;
        }

        Angle degrees(){
            this->value = ( this->value / amath::L_PI ) * 180.0f;
            return *this;
        }

        Vector2 normal(){
            return Vector2( cos( this->value ), sin( this->value ) );
        }

        // Arithmetic operators
        Angle operator+(const Angle& other) const {
            return Angle(value + other.value);
        }

        Angle operator-(const Angle& other) const {
            return Angle(value - other.value);
        }

        Angle operator*(const Angle& other) const {
            return Angle(value * other.value);
        }

        Angle operator/(const Angle& other) const {
            if (other.value == 0) {
                throw std::runtime_error("Division by zero");
            }
            return Angle(value / other.value);
        }

        // Comparison operators
        bool operator==(const Angle& other) const {
            return value == other.value;
        }

        bool operator!=(const Angle& other) const {
            return value != other.value;
        }

        bool operator<(const Angle& other) const {
            return value < other.value;
        }

        bool operator<=(const Angle& other) const {
            return value <= other.value;
        }

        bool operator>(const Angle& other) const {
            return value > other.value;
        }

        bool operator>=(const Angle& other) const {
            return value >= other.value;
        }

        // For printing the number
        friend std::ostream& operator<<(std::ostream& os, const Angle& num) {
            os << num.value;
            return os;
        }
    };


    Vector3 Vector2::xxx() const { return Vector3(this->x, this->x, this->x); }
    Vector3 Vector2::xxy() const { return Vector3(this->x, this->x, this->y); }
    Vector3 Vector2::xyx() const { return Vector3(this->x, this->y, this->x); }
    Vector3 Vector2::xyy() const { return Vector3(this->x, this->y, this->y); }
    Vector3 Vector2::yxx() const { return Vector3(this->y, this->x, this->x); }
    Vector3 Vector2::yxy() const { return Vector3(this->y, this->x, this->y); }
    Vector3 Vector2::yyx() const { return Vector3(this->y, this->y, this->x); }
    Vector3 Vector2::yyy() const { return Vector3(this->y, this->y, this->y); }
    Vector2 Vector2::xx () const { return Vector2(this->x,this->x); }
    Vector2 Vector2::xy () const { return Vector2(this->x,this->y); }
    Vector2 Vector2::yy () const { return Vector2(this->y,this->y); }
    Vector2 Vector2::yx () const { return Vector2(this->y,this->x); }

    Vector3 Vector3::xxx() const { return Vector3(this->x, this->x, this->x); }
    Vector3 Vector3::xxy() const { return Vector3(this->x, this->x, this->y); }
    Vector3 Vector3::xxz() const { return Vector3(this->x, this->x, this->z); }
    Vector3 Vector3::xyx() const { return Vector3(this->x, this->y, this->x); }
    Vector3 Vector3::xyy() const { return Vector3(this->x, this->y, this->y); }
    Vector3 Vector3::xyz() const { return Vector3(this->x, this->y, this->z); }
    Vector3 Vector3::xzx() const { return Vector3(this->x, this->z, this->x); }
    Vector3 Vector3::xzy() const { return Vector3(this->x, this->z, this->y); }
    Vector3 Vector3::xzz() const { return Vector3(this->x, this->z, this->z); }
    Vector3 Vector3::yxx() const { return Vector3(this->y, this->x, this->x); }
    Vector3 Vector3::yxy() const { return Vector3(this->y, this->x, this->y); }
    Vector3 Vector3::yxz() const { return Vector3(this->y, this->x, this->z); }
    Vector3 Vector3::yyx() const { return Vector3(this->y, this->y, this->x); }
    Vector3 Vector3::yyy() const { return Vector3(this->y, this->y, this->y); }
    Vector3 Vector3::yyz() const { return Vector3(this->y, this->y, this->z); }
    Vector3 Vector3::yzx() const { return Vector3(this->y, this->z, this->x); }
    Vector3 Vector3::yzy() const { return Vector3(this->y, this->z, this->y); }
    Vector3 Vector3::yzz() const { return Vector3(this->y, this->z, this->z); }
    Vector3 Vector3::zxx() const { return Vector3(this->z, this->x, this->x); }
    Vector3 Vector3::zxy() const { return Vector3(this->z, this->x, this->y); }
    Vector3 Vector3::zxz() const { return Vector3(this->z, this->x, this->z); }
    Vector3 Vector3::zyx() const { return Vector3(this->z, this->y, this->x); }
    Vector3 Vector3::zyy() const { return Vector3(this->z, this->y, this->y); }
    Vector3 Vector3::zyz() const { return Vector3(this->z, this->y, this->z); }
    Vector3 Vector3::zzx() const { return Vector3(this->z, this->z, this->x); }
    Vector3 Vector3::zzy() const { return Vector3(this->z, this->z, this->y); }
    Vector3 Vector3::zzz() const { return Vector3(this->z, this->z, this->z); }
    Vector2 Vector3::xx () const { return Vector2(this->x,this->x); }
    Vector2 Vector3::xy () const { return Vector2(this->x,this->y); }
    Vector2 Vector3::xz () const { return Vector2(this->x,this->z); }
    Vector2 Vector3::yy () const { return Vector2(this->y,this->y); }
    Vector2 Vector3::yx () const { return Vector2(this->y,this->x); }
    Vector2 Vector3::yz () const { return Vector2(this->y,this->z); }
    Vector2 Vector3::zz () const { return Vector2(this->z,this->z); }
    Vector2 Vector3::zx () const { return Vector2(this->z,this->x); }
    Vector2 Vector3::zy () const { return Vector2(this->z,this->y); }

    amath::Vector2 screenSize;


    float length( amath::Vector2 in ){
        return sqrt( amath::sqrf( in.x ) + amath::sqrf( in.y ) );
    }
    
    amath::Vector2 normalize( amath::Vector2 in ){
        float length = amath::length( in );
        in.x /= length;
        in.y /= length;

        return in;
    }

    amath::Vector2 reflect( amath::Vector2& normal, amath::Vector2& ray ) {
        // Calculate the dot product of the vector and the normal
        float dotProduct = ray.x * normal.x + ray.y * normal.y;

        // Calculate the reflection using the formula: reflection = vector - 2 * dot(vector, normal) * normal
        float reflectionX = ray.x - 2 * dotProduct * normal.x;
        float reflectionY = ray.y - 2 * dotProduct * normal.y;

        return amath::Vector2(reflectionX, reflectionY);
    }

}
