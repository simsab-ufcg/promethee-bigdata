#include "optimized/promethee_opt.h"
#include "vanilla/promethee_vanilla.h"
#include "umbu/promethee_umbu.h"
#include "threads/promethee_thread.h"
#include "parse_args.h"
#include <time.h>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]){

  vector<string> args = convertToVector(argc, argv);

  bool isVan = hasFlag(args, "-van");
  bool isUmbu = hasFlag(args, "-um");
  bool isThread = hasFlag(args, "-thr");
  bool isOpt = !isVan && !isUmbu && !isThread;
  
  string hq_flag = getCmdOption(args, "-hq");
  int divideBy = -1;

  if(hq_flag.size()){
    divideBy = atoi(hq_flag.c_str());
  }

  Promethee* res;
  if(isOpt)
    res = new PrometheeOpt();
  else if(isVan)
    res = new PrometheeVanilla();
  else if(isUmbu)
    res = new PrometheeUmbu();
  else if(isThread)
    res = new PrometheeThread();
  timespec rs;

  clock_gettime(CLOCK_MONOTONIC, &rs);
  long long secondsA = rs.tv_sec, nanoA = rs.tv_nsec;

  res->init(args, divideBy);

  clock_gettime(CLOCK_MONOTONIC, &rs);
  long long secondsB = rs.tv_sec, nanoB = rs.tv_nsec;  

  ldouble result = ( secondsB + nanoB * pow(10, -9) ) - ( secondsA + nanoA * pow(10, -9) );
  printf("Init: %.8lf\n", result);


  clock_gettime(CLOCK_MONOTONIC, &rs);
  secondsA = rs.tv_sec, nanoA = rs.tv_nsec;  

  res->process();
  
  clock_gettime(CLOCK_MONOTONIC, &rs);
  secondsB = rs.tv_sec, nanoB = rs.tv_nsec;  
  
  result = ( secondsB + nanoB * pow(10, -9) ) - ( secondsA + nanoA * pow(10, -9) );
  
  printf("Process: %.8lf\n", result);
  return 0;
}
