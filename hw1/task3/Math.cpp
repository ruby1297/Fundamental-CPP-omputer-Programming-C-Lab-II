class Math {
private:
	static const double PI;
public:
	static double getPI() {
		const double PI = 3.14159;
		return PI;
	}

	static double abs(double a) {
		if (a < 0)
			return -a;
		return a;
	}

	static double add(double a, double b) {
		return (a + b);
	}

	static double sub(double a, double b) {
		return (a - b);
	}

	static double min(double a, double b) {
		if (a < b)
			return a;
		return b;
	}

	static double min(double arr[]) {
		double min = arr[0];
		for (int i = 0; i < sizeof(arr); i++) {
			if (arr[i] < min)
				min = arr[i];
		}
		return min;
	}

	static double max(double a, double b) {
		if (a < b)
			return b;
		return a;
	}

	static double max(double arr[]) {
		double max = arr[0];
		for (int i = 0; i < sizeof(arr); i++) {
			if (max < arr[i])
				max = arr[i];
		}
		return max;
	}

	static double pow(double a, int n) {
		for (int i = 0; i < n; i++)
			a *= a;

		return a;
	}

	static double avg(double a, double b) {
		return (a + b) / 2;
	}

	static double avg(double arr[]) {
		double sum = 0;
		for (int i = 0; i < sizeof(arr); i++) {
			sum += arr[i];
		}

		return sum / sizeof(arr);
	}

};
