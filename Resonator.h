#pragma once
#include <cmath>

#ifndef M_PI
	#define M_PI 3.14159265358979323846
#endif

class Resonator {
public:
	Resonator(double sampleRate = 44100.0)
		: fs(sampleRate)
		, a1(0.0)
		, a2(0.0)
		, b0(0.0)
		, y1(0.0)
		, y2(0.0)
		, x1(0.0)
		, x2(0.0) { }

	void setParams(double f0, double bw) {
		double omega = 2.0 * M_PI * f0 / fs;
		double r = exp(-M_PI * bw / fs);
		a1 = -2.0 * r * cos(omega);
		a2 = r * r;
		b0 = sin(omega);
	}

	double play(double x) {
		double y = b0 * x - a1 * y1 - a2 * y2;
		y2 = y1;
		y1 = y;
		return y;
	}

	void reset() {
		y1 = y2 = x1 = x2 = 0.0;
	}

private:
	double fs;
	double a1, a2, b0;
	double y1, y2, x1, x2;
};
