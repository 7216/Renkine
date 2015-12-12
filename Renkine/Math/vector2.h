
namespace renkine
{
	struct Vector2
	{
		float x, y;

		Vector2();
		Vector2(float x, float y);

		Vector2 add( const Vector2 &other );
		Vector2 substract( const Vector2 &other );
		Vector2 multiply( const Vector2 &other );
		Vector2 divide( const Vector2 &other );

		float magnitude();
		float length();
		float dot();

		void normalize();
		
		void lerp( const Vector2 &other, float alpha );
		void clamp( const Vector2 &min, const Vector2 &max );

		bool equals( const Vector2 &other );

		Vector2 operator + ( const Vector2 &other );
		Vector2 operator - ( const Vector2 &other );
		Vector2 operator * ( const Vector2 &other );
		Vector2 operator / ( const Vector2 &other );

		bool operator == ( const Vector2 &other );
		bool operator != ( const Vector2 &other );
						 
		void operator += ( const Vector2 &other );
		void operator -= ( const Vector2 &other );
		void operator *= ( const Vector2 &other );
		void operator /= ( const Vector2 &other );

		//friend std::ostream& operator<<(std::ostream& stream, const Vector2 &vector);
	};
}