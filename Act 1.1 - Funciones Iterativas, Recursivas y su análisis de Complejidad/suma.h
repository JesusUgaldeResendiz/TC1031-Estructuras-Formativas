#ifndef SUMA_H_INCLUDED
#define SUMA_H_INCLUDED

using namespace std;

int sumaIterativa(int n)
{
	int acum = 0;
	if(n<1){
		return 0;
	}
	else{
		for(int i =0;i<=n;i++){
			acum+=i;
		}
		return acum;
	}
}

int sumaRecursiva(int n)
{
	if(n<1){
		return 0;
	}
	else{
		return n+sumaRecursiva(n-1);
	}
}

int sumaDirecta(int n)
{
  if(n<1){
    return 0;
  }
  else{
    int result;
    result = (n*(n+1))/2;
    return result;
  }

}

#endif // SUMA_H_INCLUDED
