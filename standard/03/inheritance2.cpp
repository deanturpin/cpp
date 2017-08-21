class one {

	public:
		int p1;

	protected:
		int p2;

	private:
		int p3;
};

class two : private one {

	public:
	void init() {

		p1 = 1;
		p2 = 2;

		// error - private cannot be access by derived class
		// p3 = 3;
	}
};

class three : public two {
};

int main() {

	three o;

	// But you can call a public method in the base class which access the private
	// members
	o.init();

	return 0;
}
