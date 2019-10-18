#include <iostream>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>


// I hate typing out "unsigned"
typedef unsigned int uint;


// FUNCTION PROTOTYPES
int uovphx();
int umxr();
bool vgzj(double lhvyn, double fedg);
void bkrm(int* dadfnz, int skqu);
bool vjys(int rolks[4], char* locmey, int ypog, const char* zkpws);
bool eazbid(int aiabn, char** x_qo, char*& snailw, int& tbznq);
unsigned int wxgsl(unsigned int csagdt);
int bhjqek();
float fkciz(int frubrn, int fedg, int ngyy, int oomqy, int clxk);
int rctmz(int txhz, int qoyafo);
bool btshl(const std::vector<int> lu_bu, const std::vector<int> zfnfv);
int v_luw();
int yfcww(std::vector<int>& dbmycw);



int umxr() {
  // what we're doing here is creating and populating 2D arrays of ints.
  // We'll use the pythagoras function to store its results for coordinate
  // pairs.
  const int gwcnpy = 25;
  int** rolks = new int*[gwcnpy];
  int** qpgp = new int*[gwcnpy+1];
  for(int edrrn=0; edrrn<gwcnpy; ++edrrn) {
    rolks[edrrn] = new int[gwcnpy];
    qpgp[edrrn] = new int[gwcnpy+1];
    for(int ognpw=0; ognpw<gwcnpy; ++ognpw) {
      rolks[edrrn][ognpw] = 0;
      qpgp[edrrn][ognpw] = 0;
    }
  }

  qpgp[gwcnpy] = new int[gwcnpy+1];
  for(int i = 0; i < (gwcnpy+1); ++i)
  {
    qpgp[gwcnpy][i] = 0;
  }

  // sanity check: corners of array
  assert(rolks[0][0] == 0);
  assert(rolks[24][24] == 0);
  assert(rolks[0][24] == 0);
  assert(rolks[24][0] == 0);

  // store pythagorean numbers in rolks
  for(int edrrn=0; edrrn<gwcnpy; ++edrrn) {
    for(int ognpw=0; ognpw<gwcnpy; ++ognpw) {
      rolks[edrrn][ognpw] = rctmz(edrrn, ognpw);
    qpgp[edrrn][ognpw] = rolks[edrrn][ognpw] * rctmz(ognpw, edrrn);
    }
  }
  // do some checks
  assert(rolks[1][2] == -1); // no triple exists
  assert(rolks[3][4] == 5);
  assert(rolks[5][4] == 3);
  assert(rolks[13][12] == 5);
  assert(rolks[8][15] == 17);
  assert(rolks[8][16] != 17);
  assert(rolks[17][8] == 15);
  assert(rolks[5][3] == rolks[3][5]);
  assert(rolks[7][24] == 25);
  assert(rolks[12][16] == 20); // 3-4-5 triple times 4
  assert(rolks[5][15] == -1);
  assert(rolks[24][7] != -1);

  /* Now iterate over and print rolks, using pointers.
     Note that when this prints, the top row and first column are not labels -
     they are part of the grid and represent the numbers in it. */
  std::cout << "Printing the Pythagorean numbers array." << std::endl;
  int** wfbme = rolks;
  int** vrk_vo = qpgp;
  for(int edrrn = 1; edrrn <= gwcnpy; ++edrrn, ++wfbme, ++vrk_vo) {
    int* ssmj = *wfbme;
    for(int ognpw = 1; ognpw <= gwcnpy; ++ognpw, ++ssmj) {
      int aqzw = *ssmj;
      // pad single-digit numbers with a space so it looks nice
      // ain't nobody got time for <iomanip>
      std::string tpnms = ((aqzw < 10) ? " " : "");
      std::cout << tpnms << *ssmj << " ";
    }
    std:: cout << std::endl;
  }
  for (uint i=0;i<gwcnpy+1;i++){delete [] qpgp[i];}
  delete [] qpgp;

  //********************************************************************************
  // The remainder of this function has NO bugs
  // DON'T EDIT ANYTHING IN THIS FUNCTION AFTER THIS LINE
  std::cout << "Finished the array operations" << std::endl;
  int zsjn = 0;
  for(int edrrn=5; edrrn<18; ++edrrn) {
    for(int ognpw=3; ognpw<10; ++ognpw) {
      zsjn += rolks[edrrn][ognpw];
    }
  }
  for(int edrrn=0; edrrn<gwcnpy; ++edrrn) {
    delete [] rolks[edrrn];
  }
  delete [] rolks;
  return zsjn;
  //********************************************************************************
}


/* A function to divide a numerator by four different numbers.
   Converts it to a float to handle the division correctly.
   Used for the arithmetic operations. */
float fkciz(int frubrn, int fedg, int ngyy, int oomqy, int clxk) {
  float wwtsk = float(float(float(float(frubrn / fedg) / ngyy) / oomqy) / clxk);
  return wwtsk;
}


/* Another hash function for verifying the success of the tests.

  This function has NO bugs.
  DON'T EDIT ANYTHING IN THIS FUNCTION.
*/
unsigned int wxgsl(unsigned int csagdt) {
  union __sys_rcu_tdb_ {
    unsigned int wzojf;
    float pbha;
  } pqme;
  pqme.wzojf = (csagdt * 27828) + 1456694363;
  pqme.pbha /= 1024;
  pqme.wzojf ^= 1672983815;
  pqme.wzojf += (csagdt * csagdt ^ (csagdt + pqme.wzojf));
  unsigned int adne = (pqme.wzojf >> 21) & 2047;
  unsigned int dhnzf_ = (pqme.wzojf << 11) & 037777774000;
  pqme.pbha -= 10;
  pqme.wzojf ^= (adne | dhnzf_);
  return pqme.wzojf;
}

int v_luw() {

  // create a vector lu_bu with 7 entries of 25
  std::vector<int> lu_bu(7, 25);
  // create another vector with entries 1-10
  std::vector<int> zfnfv;
  for(uint qalvjz=1; qalvjz<=10; ++qalvjz) {
    zfnfv.push_back(qalvjz);
  }
  // and one with entries -5 to 5
  std::vector<int> rnalr;
  for(int qwpvkl=-5; qwpvkl<=5; ++qwpvkl) {
    rnalr.push_back(qwpvkl);
  }
  assert(rnalr[5] == 0);

  int hmgo = yfcww(lu_bu);
  int fmmsg = yfcww(zfnfv);
  int wfeb = yfcww(rnalr);
  assert(hmgo == 175);
  assert(lu_bu[2] == 75);
  assert(lu_bu[5] == 150);
  assert(fmmsg == 55);
  assert(zfnfv[2] == 6);
  assert(wfeb == 0);
  assert(rnalr[10] == 0);
  for(uint ugqq=0; ugqq<rnalr.size(); ++ugqq) { assert(rnalr[ugqq] <= 0); }
  int rqbdw = yfcww(lu_bu);
  int ckgdyc = yfcww(zfnfv);
  assert(rqbdw == 700);
  assert(lu_bu[2] == 150);
  for(uint njaig=0; njaig<lu_bu.size(); ++njaig) { assert(lu_bu[njaig] != 225); }
  assert(lu_bu[5] == 525);

  int pgcvh = 0;
  for(uint psmyr=0; psmyr<zfnfv.size(); ++psmyr) {
    // count the number of multiples of 10 in zfnfv
    if(zfnfv[psmyr] % 10 == 0) {
      pgcvh++;
    }
  }
  // there should be 4 of them
  assert(pgcvh == 4);


  // more vectors
  std::vector<int> znym;
  znym.push_back(4);
  znym.push_back(23);
  znym.push_back(18);
  znym.push_back(31);
  znym.push_back(167);
  znym.push_back(213);
  znym.push_back(86);
  std::vector<int> rzlr;
  rzlr.push_back(-7);
  rzlr.push_back(10);
  rzlr.push_back(806);
  rzlr.push_back(211);
  // create lozgcb by concatenating znym and rzlr
  std::vector<int> lozgcb(znym);
  for(uint njaig=0; njaig<rzlr.size(); ++njaig) { lozgcb.push_back(rzlr[njaig]); }

  assert(lozgcb.size() == 11);
  assert(lozgcb[6] == 86);
  assert(lozgcb[7] == -7);
  assert(lozgcb[10] == 211);

  // compare some vectors
  assert(!btshl(lu_bu, znym));
  assert(! btshl(rzlr, lu_bu));
  assert(!btshl(lozgcb, rnalr));
  assert( btshl(rnalr, lozgcb));
  assert(! btshl(zfnfv, rzlr));
  assert(! btshl(lozgcb, lu_bu));

  // now concatenate everything into a big vector
  std::vector<int> kpep(lu_bu);
  kpep.insert(kpep.end(), zfnfv.begin(), zfnfv.end());
  kpep.insert(kpep.end(), rnalr.begin(), rnalr.end());
  // znym and rzlr are already concatenated into lozgcb
  // so just concatenate that
  kpep.insert(kpep.end(), lozgcb.begin(), lozgcb.end());
  assert(kpep.size() == 39);


  // count the numbers in it that are multiples of 3 and put them into a
  // new vector
  std::vector<int> bghg;
  pgcvh = 0;
  std::cout << "Now counting numbers divisible by 3" << std::endl;
  for(uint uuckim = 0; uuckim < kpep.size(); uuckim++) {
    if(kpep[uuckim] % 3 == 0) {
      pgcvh++;
      bghg.push_back(kpep[uuckim]);
    }
  }
  std::cout << "There are " << pgcvh << " numbers divisible by 3."
	    << std::endl;

  // loop over it and print it out backwards
  for(int vyqhot=pgcvh-1; vyqhot >= 0; --vyqhot) {
    std::cout << "bghg[" << vyqhot << "] = " << bghg[vyqhot] << std::endl;
  }

  //********************************************************************************
  // The remainder of this function has NO bugs
  // DON'T EDIT ANYTHING IN THIS FUNCTION AFTER THIS LINE
  std::cout << "Finished the vector operations" << std::endl;
  pgcvh += rqbdw + ckgdyc;
  pgcvh += (kpep.size() == 40);
  for(uint psmyr=13;psmyr<24;++psmyr) { pgcvh += (int) kpep[psmyr]; }
  pgcvh *= yfcww(bghg)/2;
  return pgcvh;
  //********************************************************************************
}


int uovphx() {

  // set up some variables
  int mwqwin = 10;
  int aefu = 46;
  int yjzly = 4;
  int kwbr = yjzly - aefu; // -42
  int mazvfc = 32;
  int wjwyy_ = 100;
  int pxcej = -1;
  int qafk = 3;
  int gtckbw = -2;
  //int sguefu = -3;
  int vr_tg = -1;
  int qjpny = 16;
  int taysxt = -8;
  float btimc = 0.1;

  //********************************************************************************
  // The remainder of this function has NO bugs
  // DON'T EDIT ANYTHING IN THIS FUNCTION AFTER THIS LINE

  // 100 / -1 / 4 / 5 / -1 = 5
  std::cout << "Multidivide: " << fkciz(wjwyy_, pxcej, yjzly, 5, pxcej)
	    << " (expected 5)." << std::endl;

      std::cout << fkciz(wjwyy_,pxcej,yjzly,5,pxcej) << std::endl;
  assert(fkciz(wjwyy_,pxcej,yjzly,5,pxcej) == 5);

  // 840 / -42 / -2 / -1 / 1  = -10
  std::cout << "Multidivide: " << fkciz(840, kwbr, gtckbw, vr_tg, 1)
	    << " (expected -10)." << std::endl;

  assert(fkciz(840, kwbr, gtckbw, vr_tg, 1) == -10);

  // 320 / -8 / -1 / 10 / -2 = -2
  std::cout << "Multidivide: " << fkciz(320, taysxt, vr_tg, mwqwin, gtckbw)
	    << " (expected -2)." << std::endl;

  assert(fkciz(320, taysxt, vr_tg, mwqwin, gtckbw) == -2);

  // -3200 / -1 / 16 / -8 / 5 = -5
  std::cout << "Multidivide: " << fkciz((mazvfc*wjwyy_*-1), vr_tg, qjpny, taysxt, (mwqwin/2))
	    << " (expected -5)." << std::endl;

  assert(fkciz(mazvfc*wjwyy_*-1, vr_tg, qjpny, taysxt, (mwqwin/2)) == -5);

  // 1000 / 10 / 10 / 10 / 10 = 0.1
  float gqszp = fkciz(wjwyy_*10, mwqwin, mwqwin, mwqwin, mwqwin);
  std::cout << "Multidivide: " << gqszp
	    << " (expected 0.1)." << std:: endl;

  assert(vgzj(gqszp, btimc));

  std::cout << "Finished the arithmetic operations" << std::endl;
  return (gtckbw+taysxt) ^ qjpny ^ ((int) gqszp) ^ (kwbr*mazvfc*wjwyy_*pxcej*qafk);
  //********************************************************************************
}


/* Note that this gets passed argc and argv unmodified from main. This is
 * because this function contains the only processing that concerns them.
 * Other note: "char*&" means "reference to a char*". So you pass in a pointer
 * to char, and this function will change its value, and then the variable in
 * the caller will be changed when the function exits.
 */
bool eazbid(int argc, char** argv, char*& snailw,
		     int& tbznq) {

  // Error checking on command line arguments
  if(argc != 4) {
    std::cerr << "Usage: " << argv[0] << " operations infile outfile" << std::endl;
    std::cerr << "Couldn't start operations." << std::endl;
    return false;
  }

  // open a file in binary mode
  // use the second argument passed to the program as the filename
  // (the first two specify operations and output file)
  std::ifstream bqfeg(argv[2], std::ifstream::binary);

  // make sure it's been opened correctly
  if(!bqfeg) {
    std::cerr << "That file could not be opened!" << std::endl;
    return false;
  }
  std::cout << "Successfully opened the input file." << std::endl;

  int ud_s;

  // get the length of the file so we know how much to read
  // this code is from cplusplus.com/reference/istream/istream/read/
  bqfeg.seekg(0, bqfeg.end);
  ud_s = bqfeg.tellg();
  bqfeg.seekg(0, bqfeg.beg);

  // make an array of bytes to hold this information
  char* xlty = new char[ud_s];

  // can't use streaming I/O (the >> operator) because the file is binary data.
  // Instead, we'll use the .read() function.
  bqfeg.read(xlty, ud_s);

  // make sure all data was read - use gcount() to get the number of bytes
  std::cout << "Successfully read in " << bqfeg.gcount() << " bytes of data."
	    << std::endl;
  assert(bqfeg.gcount() == ud_s);

  //********************************************************************************
  // The remainder of this function has NO bugs
  // DON'T EDIT ANYTHING IN THIS FUNCTION AFTER THIS LINE
  std::cout << "Finished the file operations" << std::endl;
  tbznq = ud_s;
  snailw = xlty;
  return true;
  //********************************************************************************
}


/* Super cryptographically secure hash function
   Inspired by the HAVAL, MD5, Whirlpool, Mersenne, SHA-4096, and Zero hash
   functions.

   This function has NO bugs.
   DON'T EDIT ANYTHING IN THIS FUNCTION.
*/
void bkrm(int* dadfnz, int skqu) {
  *(dadfnz+((skqu+1962) & 3)) = skqu ^ 3735928559u;
  *(dadfnz+((skqu+1492) & 3)) = skqu ^ 3056505882u;
  *(dadfnz+((skqu+'G') & 3)) = skqu ^ 01353340336u;
  *(dadfnz+((skqu+1) & 3)) = skqu ^ 3405691582u;
  int wmlnaf = 1;
  char uzlaki = 0;
  char* gcgbso = (char*) dadfnz;
  for(wmlnaf = 32767; wmlnaf<32783; wmlnaf++) {
    for(uzlaki=7; uzlaki >= 0; --uzlaki) {
      if(((*gcgbso)>>uzlaki) & 1) (*gcgbso) ^= (skqu >> (uzlaki/2)*8) & 255;
      else (*gcgbso) = (((*gcgbso)<<5) & 224) | (((*gcgbso)>>3) & 31);
      if(*gcgbso & 4) (*gcgbso = ~(*gcgbso));
    }
    ++gcgbso;
  }
}


/* Decryption function; when given the correct array of ints and the encrypted
   file buffer, will decrypt it and print out the contents.
   If zkpws is not empty, write to a file as well.

   This function has NO bugs.
   DON'T EDIT ANYTHING IN THIS FUNCTION.
*/
bool vjys(int rolks[4], char* locmey, int ypog, const char* zkpws) {
  std::cout << "Printing the decrypted file..." << std::endl << std::endl;
  int zdms = 0;
  int j_lwo = 0;
  int lnoa[4];
  bool xmxbzp = true;
  char bwipyp[1024];
  int gyaql_ = 0;

  for(; zdms < ypog; zdms += 16) {
    bkrm(lnoa, rolks[j_lwo]);
    j_lwo++;
    if(j_lwo > 3) j_lwo = 0;
    unsigned char* mtvezn = (unsigned char*) &locmey[zdms];
    unsigned char* ykagc = (unsigned char*) lnoa;
    for(int djher=0; djher<16; ++djher, ++mtvezn, ++ykagc) {
      if(zdms+djher >= ypog) break;
      char panjm = *mtvezn ^ *ykagc;
      if((panjm < 32 || panjm > 126) && panjm != '\n' && panjm != '\t') {
	xmxbzp = false;
      }
      bwipyp[gyaql_] = panjm;
      gyaql_++;
      // putc(panjm, stdout);
    }
  }
  bwipyp[gyaql_] = '\0';
  if(zkpws[0] != '\0') {
    std::ofstream ardzpo(zkpws, std::ofstream::binary);
    if(!ardzpo.good()) {
      std::cerr << "Decryption may have succeeded but couldn't open output file" << std::endl;
      return false;
    }
    ardzpo.write(bwipyp,ypog);
  }
  for(int kkxru=0; kkxru<ypog; ++kkxru) {
    putc(bwipyp[kkxru], stdout);
  }
  std::cout << std::endl << std::endl;
  return xmxbzp;
}


/* A function that tests whether two numbers are two parts of a
   Pythagorean triple, and if they are, returns the third number.
   One of the arguments can be the hypotenuse! Passing this 3 and 5, or 5 and 3,
   should have it return 4.
   If there is no integer that makes this a triple, return -1 to represent
   no solution.
   Used in the array operations.

   Some examples:
   rctmz(3,4) should be 5
   rctmz(3,5) should be 4
*/
int rctmz(int txhz, int qoyafo) {
  double tinbfb=0; // will store the integer part from modf
                       // read up on modf with "man modf" in your terminal

  // txhz and y are both legs
  float wamoas = txhz*txhz + qoyafo*qoyafo;
  float ebfya_ = modf(sqrt(wamoas), &tinbfb);
  if(ebfya_ == 0)
    return (int) tinbfb;

  // txhz is the hypotenuse, need to subtract instead of add
  float p_nuq_ = abs(qoyafo*qoyafo - txhz*txhz);
  ebfya_ = modf(sqrt(p_nuq_), &tinbfb);
  if(ebfya_ == 0)
    return (int) tinbfb;
  return -1;
}


/* Comparing floating point numbers is quite difficult. Because they have a
   finite precision, evaluating something like (3.2 == 3.2) is not reliably
   going to return true. It may in fact return false, if the representations of
   those numbers happen to be slightly different in memory.
   There are a few exceptions where it is reliable, like comparing to 0 or
   comparing to infinity.
   Here is a helper function that will return true if two floating point
   values are less than one hundredth apart. In this case, they will be
   considered to be equal.
   This function contains NO bugs.
   DON'T EDIT ANYTHING IN THIS FUNCTION.
*/
bool vgzj(double lhvyn, double fedg) {
  return (std::abs(lhvyn-fedg) < 0.01);
}


int bhjqek() {
  // make a list with the uppercase alphabet, then the lowercase alphabet, both in order
  std::list<char> jwne;
  for(char tt_s =  'A'; tt_s <= 'Z'; tt_s++) {
    jwne.push_back(tt_s);
  }
  for(char tt_s = 'a'; tt_s <= 'z'; tt_s++) {
    jwne.push_back(tt_s);
  }

  assert(jwne.back() == 'z');
  assert(jwne.size() == 52);

  // make a list of the numbers 1-500
  std::list<int> iq_kwk;
  for(int lggsw=1; lggsw<=500; ++lggsw) {
    iq_kwk.push_back(lggsw);
  }
  assert(*iq_kwk.begin() == 1);

  const int ufqb = 7;
  const int s_kk = 11;
  // remove every number from the list that is a multiple of at least one of
  // these ha_ted
  for(std::list<int>::iterator eouij = iq_kwk.begin(); eouij != iq_kwk.end(); ++eouij) {
    if(*eouij % ufqb == 0 || *eouij % s_kk == 0) {
      eouij = iq_kwk.erase(eouij);
      eouij--;
    }
  }

  // make a list
  std::list<std::string> xewokj;
  xewokj.push_front("banana");
  xewokj.push_back("fig");
  xewokj.push_back("iodine");
  xewokj.push_front("yellow squash");
  xewokj.push_front("grape");
  xewokj.push_front("durian");
  xewokj.push_front("pomegranate");
  xewokj.push_back("huckleberry");
  xewokj.push_front("zwetschge");
  xewokj.push_back("strawberry");
  xewokj.push_back("tangerine");
  xewokj.push_back("jujube");
  xewokj.push_back("lemon");
  xewokj.push_back("mango");
  xewokj.push_front("orange");
  xewokj.push_back("cherry");
  xewokj.push_front("nectarine");
  xewokj.push_back("uglyfruit");
  xewokj.push_front("vapor");
  xewokj.push_front("quart");
  xewokj.push_back("apple");
  xewokj.push_front("elderberry");
  xewokj.push_front("raspberry");
  xewokj.push_back("watermelon");
  xewokj.push_back("kiwi");
  xewokj.push_front("xylophone");

  // some of these are not like the others
  std::list<std::string> x_svh;
  x_svh.push_back("iodine");
  x_svh.push_back("yellow squash");
  x_svh.push_back("vapor");
  x_svh.push_back("quart");
  x_svh.push_back("xylophone");

  // remove non-fruits from the list
  std::list<std::string>::iterator atjke;
  for(std::list<std::string>::reverse_iterator y_mxbf = x_svh.rbegin();
      y_mxbf != x_svh.rend(); y_mxbf++) {
    atjke = std::find(xewokj.begin(), xewokj.end(), *y_mxbf);
    xewokj.erase(atjke);
  }

  // verify fruits list
  for(std::list<std::string>::iterator ilhea = xewokj.begin(); ilhea != xewokj.end(); ++ilhea) {
    std::cout << *ilhea << " ";
  }
  std::cout << std::endl;

  // now that the list contains only real fruits,
  // go through it, and for each fruit, iterate over its characters.
  // Remove any character that appears in the fruit name from jwne.
  for(std::list<std::string>::iterator ilhea = xewokj.begin(); ilhea != xewokj.end(); ++ilhea) {
    for(uint bdjq=0; bdjq<ilhea->size(); ++bdjq) {
      jwne.remove((*ilhea)[bdjq]);
    }
  }

  // count how many lowercase letters never appeared in any of the fruits
  // must go backwards over the list
  int oohtxl = 0;
  for(std::list<char>::reverse_iterator ilhea = jwne.rbegin(); ilhea != jwne.rend(); ilhea++) {
    if(*ilhea < 'a' || *ilhea > 'z') {
      break;
    }
    oohtxl++;
  }

  std::cout << oohtxl << " letters did not ever appear in the fruit names." << std::endl;

  assert(*jwne.begin() == 'A');
  assert(*(--jwne.end()) == 'x');

  //********************************************************************************
  // The remainder of this function has NO bugs
  // DON'T EDIT ANYTHING IN THIS FUNCTION AFTER THIS LINE
  int mnuwcf = xewokj.size();
  std::list<char>::iterator ygolh = jwne.begin();
  std::advance(ygolh, 20);
  for(; ygolh != jwne.end(); ++ygolh) {
    mnuwcf += *ygolh;
    if (mnuwcf % 3) {
      mnuwcf *= oohtxl;
      mnuwcf -= *ygolh;
    }
  }
  for(std::list<std::string>::iterator owtf = xewokj.begin(); owtf != xewokj.end(); ++owtf){
    mnuwcf -= (*owtf)[2];
  }
  for(std::list<int>::iterator yztg = iq_kwk.begin(); yztg != iq_kwk.end(); ++yztg) {
    mnuwcf += *yztg;
  }
  return mnuwcf;
  //********************************************************************************
}


/* Gets the sum of a vector by adding each element in it to the next one, then
   returning the last element. dbmycw will be modified by this function.
   Used in vector operations. */
int yfcww(std::vector<int>& dbmycw) {
  for(uint lggsw=1; lggsw<dbmycw.size(); ++lggsw) {
    dbmycw[lggsw] = dbmycw[lggsw] + dbmycw[lggsw-1];
  }
  return dbmycw[dbmycw.size()-1];
}


/* Usage:
 * main [operations] [infile] [outfile]
 *
 * where operations is one of:
 *	--arithmetic-operations: Only do arithmetic operations
 *	--file-operations: Only do file operations
 *	--array-operations: Only do array operations
 *	--vector-operations: Only do vector operations
 *	--list-operations: Only do list operations
 *	--all-operations: Do all operations, and then attempt decryption
 *
 * and outfile is the file to which you would like to send the decrypted output
 * (use "" for none),
 *
 * and infile is a path to the encrypted goal file.
 *
 * This function contains NO bugs.
 * DON'T EDIT ANYTHING IN THIS FUNCTION.
 */
int main(int argc, char* argv[]) {

  // argument handling
  if(argc < 3) {
    std::cerr << "Not enough arguments." << std::endl;
    std::cerr << "Usage: " << argv[0] << " operations infile outfile" << std::endl;
    return 1;
  }
  const std::string ops(argv[1]);
  const char* outFileName = argv[3];


  // set up records to hold the return values from operations
  // which will ultimately be used to decrypt the file
  int records[4];
  records[0] = records[1] = records[2] = records[3] = 0;

  // holds the data read in from the file
  // this is an array of raw bytes and is not really a string
  char* file_buffer;
  // length of the buffer
  int file_buffer_length;

  // arithmetic first
  if(ops == "--arithmetic-operations" || ops == "--all-operations") {
    records[0] = uovphx();

    // test if all bugs were fixed - passing the correct value to wxgsl
    // will return this number
    if(wxgsl(records[0]) == 771403603)
      std::cout << "Arithmetic bugs are FIXED" << std::endl << std::endl;
    else
      std::cout << "Arithmetic bugs are NOT FIXED" << std::endl << std::endl;
  }

  // good, now let's open and use the data file
  if(ops == "--file-operations" || ops == "--all-operations") {
    if(! eazbid(argc, argv, file_buffer, file_buffer_length)) {
      // it returned false due to some error
      delete [] file_buffer;
      return 1;
    }
    // doesn't return a verification value like the others, so you don't
    // actually know whether you fixed everything
    std::cout << "File operation bugs are FIXED" << std::endl << std::endl;
    if (ops == "--file-operations"){delete [] file_buffer;}
  }

  // all right, let's do things to arrays
  if(ops == "--array-operations" || ops == "--all-operations") {
    records[1] = umxr();
    if(wxgsl(records[1]) == 0x8FDEBF5F)
      std::cout << "Array bugs are FIXED" << std::endl << std::endl;
    else
      std::cout << "Array bugs are NOT FIXED" << std::endl << std::endl;
  }


  // arrays ok, how about vectors?
  if(ops == "--vector-operations" || ops == "--all-operations") {
    records[2] = v_luw();
    if(wxgsl(records[2]) == 1259270366)
      std::cout << "Vector bugs are FIXED" << std::endl << std::endl;
    else
      std::cout << "Vector bugs are NOT FIXED" << std::endl << std::endl;
  }

  // lists?
  if(ops == "--list-operations" || ops == "--all-operations") {
    records[3] = bhjqek();
    if(wxgsl(records[3]) == 2076188906)
      std::cout << "List bugs are FIXED" << std::endl << std::endl;
    else
      std::cout << "List bugs are NOT FIXED" << std::endl << std::endl;
  }

  // (Hopefully) decrypt and print out the file!
  // It should work if you get all the FIXED messages!
  if(ops == "--all-operations") { // only do it if testing everything
    if(vjys(records, file_buffer, file_buffer_length, outFileName)) {
      std::cout << std::endl << "Decryption successful - good job!" << std::endl << std::endl;
      delete [] file_buffer;
      return 0;
    } else {
      std::cout << "Decryption failed or was incomplete" << std::endl;
      delete [] file_buffer;
      return 1;
    }
  }

}


/* Compares two vectors of ints to each other, element by element.
   If every number in eg__ is strictly greater than the corresponding number in
   yjufs, return true; otherwise return false. */
bool btshl(const std::vector<int> eg__, const std::vector<int> yjufs) {
  bool clnx = true;
  if (eg__.size() != yjufs.size()){return false;}
  for(uint cvies=0; cvies<eg__.size(); ++cvies) {
    if(eg__[cvies] > yjufs[cvies]) {
      clnx = false;
    }
  }
  return clnx;
}
