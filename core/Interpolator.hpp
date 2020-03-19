#ifndef interpolator
#define Interpolator

class Interpolator{
public:
	double liniar(int xl,int xr,int x0,int wl,int wr)
	{
		double a=(wr-wl)/(xr-xl);
		double b=wr-a*xr;
		return x0*a+b;
	}
};
#endif
