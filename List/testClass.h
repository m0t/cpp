template <class T> class Test{
	public:
		Test(T p_data){
			data = p_data;
		}

		T getData();

	private:
		T data;
};

class Bar{
	int integ;
};