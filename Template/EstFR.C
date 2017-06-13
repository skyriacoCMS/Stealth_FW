#include <TH1D.h>
#include <TMath.h>
#include <iostream>
#include <fstream>

void EstFR(int ibatch,int ikind){


  string fin=""; 

  if(ikind == 0) fin = "../NJ3subjf/JetTrees/jetTrees.root";
  if(ikind > 0 ) fin = "./JetTrees/jetTrees.root";

  const char *finc = fin.c_str();

  TFile *f1 = new TFile(finc);

  TH2D *NJLT   = new TH2D("NJLT","",5,0,5,5,0,5);
  TH2D *NJLTen = new TH2D("NJLTen","",5,0,5,5,0,5);
  TH2D *NJLTenh = new TH2D("NJLTenh","",5,0,5,5,0,5);
  TH2D *NJLTenl = new TH2D("NJLTenl","",5,0,5,5,0,5);

  TH1D *L0 = new TH1D("L0","",200,0,2000);
  TH1D *L1 = new TH1D("L1","",200,0,2000);
  TH1D *T1 = new TH1D("T1","",200,0,2000);

  TH1D *LR = new TH1D("LR","",200,0,2000);
  TH1D *TR = new TH1D("TR","",200,0,2000);

  TH1D *LT00Mc  = new TH1D("LT00Mc","",50,0,1000); //,10,-5,5);                              
  TH1D *LT10Mc  = new TH1D("LT10Mc","",50,0,1000); //,10,-5,5);                              
  TH1D *LT11Mc  = new TH1D("LT11Mc","",50,0,1000); //,10,-5,5);                              
  TH1D *LT20Mc  = new TH1D("LT20Mc","",50,0,1000); //,10,-5,5);                              
  TH1D *LT21Mc  = new TH1D("LT21Mc","",50,0,1000); //,10,-5,5);                              
  TH1D *LT21MTc = new TH1D("LT21MTc","",50,0,1000); //,10,-5,5);                             
  TH1D *LT22Mc  = new TH1D("LT22Mc","",50,0,1000); //,10,-5,5);                              

  TH1D *LT22dr = new TH1D("LT22dr","",100,0,10);
  TH1D *LT20dr = new TH1D("LT20dr","",100,0,10);
  TH1D *LT21dr = new TH1D("LT21dr","",100,0,10);


  TH1D *LT22drc = new TH1D("LT22drc","",100,0,10);
  TH1D *LT20drc = new TH1D("LT20drc","",100,0,10);
  TH1D *LT21drc = new TH1D("LT21drc","",100,0,10);




  //Plots for sig comp  -en 
  TH1D *LT00M  = new TH1D("LT00M","",50,0,1000); //,10,-5,5);                              
  TH1D *LT10M  = new TH1D("LT10M","",50,0,1000); //,10,-5,5);                              
  TH1D *LT11M  = new TH1D("LT11M","",50,0,1000); //,10,-5,5);                              
  TH1D *LT20M  = new TH1D("LT20M","",50,0,1000); //,10,-5,5);                              
  TH1D *LT21M  = new TH1D("LT21M","",50,0,1000); //,10,-5,5);                              
  TH1D *LT21MT = new TH1D("LT21MT","",50,0,1000); //,10,-5,5);                             
  TH1D *LT22M  = new TH1D("LT22M","",50,0,1000); //,10,-5,5);                              

  TH1D *LT00Mav  = new TH1D("LT00Mav","",50,0,1000); //,10,-5,5);                          
  TH1D *LT20Mav  = new TH1D("LT20Mav","",50,0,1000); //,10,-5,5);                          
  TH1D *LT21Mav  = new TH1D("LT21Mav","",50,0,1000); //,10,-5,5);                          
  TH1D *LT22Mav  = new TH1D("LT22Mav","",50,0,1000); //,10,-5,5);                          

  TH2F *LT20M_2d  = new TH2F("LT20M_2d","",50,0,1000,50,0,1000);
  TH2F *LT21M_2d  = new TH2F("LT21M_2d","",50,0,1000,50,0,1000);
  TH2F *LT22M_2d  = new TH2F("LT22M_2d","",50,0,1000,50,0,1000);


  TH1D *LT20ht     = new TH1D("LT20ht","",30,1000,4000);
  TH1D *LT21ht     = new TH1D("LT21ht","",30,1000,4000);
  TH1D *LT22ht     = new TH1D("LT22ht","",30,1000,4000);
  TH1D *LT10ht     = new TH1D("LT10ht","",30,1000,4000);
  TH1D *LT11ht     = new TH1D("LT11ht","",30,1000,4000);
  TH1D *LT00ht     = new TH1D("LT00ht","",30,1000,4000);


  TH1D *LT20htc     = new TH1D("LT20htc","",30,1000,4000);
  TH1D *LT21htc     = new TH1D("LT21htc","",30,1000,4000);
  TH1D *LT22htc     = new TH1D("LT22htc","",30,1000,4000);
  TH1D *LT10htc     = new TH1D("LT10htc","",30,1000,4000);
  TH1D *LT11htc     = new TH1D("LT11htc","",30,1000,4000);
  TH1D *LT00htc     = new TH1D("LT00htc","",30,1000,4000);




  TH2F *LT22m_ht   = new TH2F("LT22m_ht","",30,1000,4000,50,0,1000);
  TH2F *LT21m_ht   = new TH2F("LT21m_ht","",30,1000,4000,50,0,1000);
  TH2F *LT20m_ht   = new TH2F("LT20m_ht","",30,1000,4000,50,0,1000);

  
  //Plots for sig comp  -en higherror 
  TH1D *LT00Mh  = new TH1D("LT00Mh","",50,0,1000); //,10,-5,5);                              
  TH1D *LT10Mh  = new TH1D("LT10Mh","",50,0,1000); //,10,-5,5);                              
  TH1D *LT11Mh  = new TH1D("LT11Mh","",50,0,1000); //,10,-5,5);                              
  TH1D *LT20Mh  = new TH1D("LT20Mh","",50,0,1000); //,10,-5,5);                              
  TH1D *LT21Mh  = new TH1D("LT21Mh","",50,0,1000); //,10,-5,5);                              
  TH1D *LT21MTh = new TH1D("LT21MTh","",50,0,1000); //,10,-5,5);                             
  TH1D *LT22Mh  = new TH1D("LT22Mh","",50,0,1000); //,10,-5,5);                              

  TH1D *LT00Mavh  = new TH1D("LT00Mavh","",50,0,1000); //,10,-5,5);                          
  TH1D *LT20Mavh  = new TH1D("LT20Mavh","",50,0,1000); //,10,-5,5);                          
  TH1D *LT21Mavh  = new TH1D("LT21Mavh","",50,0,1000); //,10,-5,5);                          
  TH1D *LT22Mavh  = new TH1D("LT22Mavh","",50,0,1000); //,10,-5,5);                          

  TH2F *LT20M_2dh  = new TH2F("LT20M_2dh","",50,0,1000,50,0,1000);
  TH2F *LT21M_2dh  = new TH2F("LT21M_2dh","",50,0,1000,50,0,1000);
  TH2F *LT22M_2dh  = new TH2F("LT22M_2dh","",50,0,1000,50,0,1000);


  TH1D *LT20hth     = new TH1D("LT20hth","",30,1000,4000);
  TH1D *LT21hth     = new TH1D("LT21hth","",30,1000,4000);
  TH1D *LT22hth     = new TH1D("LT22hth","",30,1000,4000);

  TH1D *LT10hth     = new TH1D("LT10hth","",30,1000,4000);
  TH1D *LT11hth     = new TH1D("LT11hth","",30,1000,4000);
  TH1D *LT00hth     = new TH1D("LT00hth","",30,1000,4000);
  TH2F *LT22m_hth   = new TH2F("LT22m_hth","",30,1000,4000,50,0,1000);
  TH2F *LT21m_hth   = new TH2F("LT21m_hth","",30,1000,4000,50,0,1000);
  TH2F *LT20m_hth   = new TH2F("LT20m_hth","",30,1000,4000,50,0,1000);

  TH1D *LT10htl     = new TH1D("LT10htl","",30,1000,4000);
  TH1D *LT11htl     = new TH1D("LT11htl","",30,1000,4000);
  TH1D *LT00htl     = new TH1D("LT00htl","",30,1000,4000);
  TH1D *LT20htl     = new TH1D("LT20htl","",30,1000,4000);
  TH1D *LT21htl     = new TH1D("LT21htl","",30,1000,4000);
  TH1D *LT22htl     = new TH1D("LT22htl","",30,1000,4000);




  L0->Sumw2(); 
  L1->Sumw2(); 
  T1->Sumw2(); 

  LR->Sumw2(); 
  TR->Sumw2(); 



  LT20htc->Sumw2();
  LT21htc->Sumw2();
  LT22htc->Sumw2();
  LT10htc->Sumw2();
  LT11htc->Sumw2();
  LT00htc->Sumw2();

  LT20ht->Sumw2();
  LT21ht->Sumw2();
  LT22ht->Sumw2();
  LT10ht->Sumw2();
  LT11ht->Sumw2();
  LT00ht->Sumw2();



  vector<float> *ak8pt; 
  vector<float> *ak8phi; 
  vector<float> *ak8eta; 
  vector<float> *ak8m; 
  
  vector<int>   *isL; 
  vector<int>   *isT; 
  float HTak4; 


  ev->SetBranchAddress("htak4",&HTak4);
  ev->SetBranchAddress("ak8pt",&ak8pt);
  ev->SetBranchAddress("ak8eta",&ak8eta);
  ev->SetBranchAddress("ak8phi",&ak8phi);
  ev->SetBranchAddress("ak8m",&ak8m);
  ev->SetBranchAddress("isLoose",&isL);
  ev->SetBranchAddress("isTight",&isT);
  int entt = ev->GetEntries();
  int initial = (ibatch)*10000; 
  int final  = (ibatch +1)*10000;
  if(final > entt ) final = entt; 

  for(int iev = initial; iev < final;iev++){
    ev->GetEntry(iev);

    if((*ak8pt).size() != 3) continue;
    //    if((*ak8pt)[0] > 1000) continue;
    // if((*ak8pt)[1] > 1000) continue;
    //if((*ak8pt)[2] > 1000) continue;


    //    if((*ak8pt)[0] > 600 ) continue; 
    //   if((*ak8pt)[1] > 600 ) continue; 
    ///  if((*ak8pt)[2] > 600 ) continue; 
    
    if(iev % 10 == 0 ) cout<<"ev :"<<iev<<endl;
    
    int ist = 0; 
    int isl = 0; 

    //Characterize
    int jsize = (*ak8pt).size(); 
    for(int ij = 0; ij < jsize ; ij ++ ){
      float jpt = (*ak8pt)[ij];
      



      if((*isL)[ij] == 1 ) isl++; 
      if((*isT)[ij] == 1 ) ist++; 
      
    }


    
    if(isl == 2 && ist == 0 ) LT20htc->Fill(HTak4);
    if(isl == 2 && ist == 1 ) LT21htc->Fill(HTak4);
    if(isl == 2 && ist == 2 ) LT22htc->Fill(HTak4);

    if(isl == 1 && ist == 0 ) LT10htc->Fill(HTak4);
    if(isl == 1 && ist == 1 ) LT11htc->Fill(HTak4);
    if(isl == 0 ) LT00htc->Fill(HTak4);





  for(int ij = 0; ij < jsize ; ij ++ ){
    float jprm = (*ak8m)[ij];
    
    bool isloose = false;
    bool istight = false;
    if((*isL)[ij] == 1 ) isloose = true; 
    if((*isT)[ij] == 1 ) istight = true;


    

    float mindr = 99; 
    TVector3 jv1,jv2; 
    float jpt = (*ak8pt)[ij]; 
    float jphi = (*ak8phi)[ij]; 
    float jeta = (*ak8eta)[ij]; 

    jv1.SetPtEtaPhi(jpt,jeta,jphi);
    for(int ijk = 0; ijk < jsize; ijk++){

      if(ijk == ij) continue;
      float jpt = (*ak8pt)[ijk]; 
      float jphi = (*ak8phi)[ijk]; 
      float jeta = (*ak8eta)[ijk]; 
      jv2.SetPtEtaPhi(jpt,jeta,jphi);
      float dr = jv1.DeltaR(jv2);
      if(dr < mindr) mindr = dr; 
    }

    if( ist == 0 && isl == 2 && isloose) {
      LT20drc->Fill(mindr);
    }

    if( ist == 1 && isl == 2 &&  istight) {
      LT21drc->Fill(mindr);
    }

    if( ist == 2 && isl == 2 &&  istight) {
      LT22drc->Fill(mindr);
    }
 


    
    if(ist == 0 && isl == 0 ){
      LT00Mc->Fill(jprm);
    }
    if(isl == 1 && ist == 0){
      if(isloose)  LT10Mc->Fill(jprm);
    }
    if(isl == 1 && ist == 1){
      if(isloose ) LT11Mc->Fill(jprm);
    }
    if(isl == 2 && ist == 0 ){
      if(isloose) LT20Mc->Fill(jprm);
    }
    if(isl == 2  && ist == 1 ){
      if(isloose ) LT21Mc->Fill(jprm);
    }
    if( isl== 2 && ist == 1 ) {
      if(istight) LT21MTc->Fill(jprm);
    }
    if( isl == 2 &&  ist  == 2 ) {
      if(isloose ) LT22Mc->Fill(jprm);
    }

  }
    
    //Fill for rates
    for(int ij = 0; ij < (*ak8pt).size(); ij ++ ){
      float jpt = (*ak8pt)[ij];
      if(isl == 0 ) L0->Fill(jpt);
      if(isl == 1  && (*isL)[ij] == 1 ) L1->Fill(jpt); 
      if(isl == 1  && ist == 1 &&  (*isT)[ij] == 1 ) T1->Fill(jpt);
    }
    NJLT->Fill(ist,isl);
  }

  TR->Divide(T1,L1,1.,1.,"B");
  LR->Divide(L1,L0,1.,1.,"B");



  // CAN now do ensemble method


  TRandom3 rr; 
  
  int itries = 150;  
  int entt = ev->GetEntries();
  for(int iev = initial; iev  < final;iev++){
    ev->GetEntry(iev);
    if(iev % 10 == 0 ) cout<<"ev :"<<iev<<" of "<<ev->GetEntries()<<endl;
    //   if((*ak8pt)[0] > 600 ) continue; 
    // if((*ak8pt)[1] > 600 ) continue; 
    // if((*ak8pt)[2] > 600 ) continue; 

    
    if((*ak8pt).size() != 3) continue;
    //    if((*ak8pt)[0] > 1000) continue;
    // if((*ak8pt)[1] > 1000) continue;
    //if((*ak8pt)[2] > 1000) continue;




    
    for( int i  = 0; i < itries; i++){
      int ist = 0; 
      int isl = 0; 
     
      int istl = 0; 
      int isll = 0; 
     
      int isth = 0; 
      int islh = 0; 
      
      int jsize = (*ak8pt).size(); 
      int it1 = 0; 
      int it2 = 0; 
      int it3 = 0; 
      int il1 = 0; 
      int il2 = 0; 
      int il3 = 0; 


      int it1h = 0; 
      int it2h = 0; 
      int it3h = 0; 
      int il1h = 0; 
      int il2h = 0; 
      int il3h = 0; 

      float mindr1 = 99; 
      float mindr2 = 99; 
      float mindr3 = 99; 
      


      for(int ij = 0; ij < jsize ; ij++){ 
	float jetPt = (*ak8pt)[ij]; 
	float jeteta = (*ak8eta)[ij]; 


	/*
	int bin = TR->FindBin(jetPt);
     	double rateT  = TR->GetBinContent(bin);
     	double rateTh = TR->GetBinContent(bin) + TR->GetBinError(bin);
     	double rateTl = TR->GetBinContent(bin) - TR->GetBinError(bin);

	bin = LR->FindBin(jetPt);
	double rateL  = LR->GetBinContent(bin);
     	double rateLh = LR->GetBinContent(bin) + LR->GetBinError(bin);
     	double rateLl = LR->GetBinContent(bin) - LR->GetBinError(bin);
	*/

	float etaparl =  -0.01561; 
	float etapart =  0.2683; 

	float par0  = 0.006348; //2694; 
	float par0l = 0.006348-0.000486;//2694 -0.01011; 
	float par0h = 0.006348+0.000486; //2694 +0.01011;
	double par1  =  1.181*1./100000.0; 
	double par2  = -5.494*1./1000000000.0; 
 
	float part0   = -0.009079; 
	float part0l  = -0.009079 - 0.004378; 
	float part0h  = -0.009079 + 0.004378; 
	float part1   = 0.0002042; 

	
	/*
	float par0  = -0.02694; 
	float par0l = -0.02694 -0.01011; 
	float par0h = -0.02694 +0.01011;
	float par1  = 0.02358; 
	float par2  = 0.07598; 
 
	float part0   = -0.009079; 
	float part0l  = -0.009079 - 0.004378; 
	float part0h  = -0.009079 + 0.004378; 
	float part1   = 0.0002042; 

	float etaparl =  -0.01564; 
	float etapart =  0.2683; 
	double rateT  = (jetPt*part1 +  part0)*(pow(jeteta,2)*etapart+1); 
	double rateTl = (jetPt*part1 + part0l)*(pow(jeteta,2)*etapart+1); 
	double rateTh = (jetPt*part1 + part0h)*(pow(jeteta,2)*etapart+1); 


	double rateL  = (par1*pow(jetPt,par2)   + par0)*(pow(jeteta,2)*etaparl+1); 
	double rateLl = (par1*pow(jetPt,par2)   + par0l)*(pow(jeteta,2)*etaparl+1); 
	double rateLh = (par1*pow(jetPt,par2)   + par0h)*(pow(jeteta,2)*etaparl+1); 

	*/

	double rateT  = (jetPt*part1 + part0)*(pow(jeteta,2)*etapart+1); 
	double rateTl = (jetPt*part1 + part0l)*(pow(jeteta,2)*etapart+1); 
	double rateTh = (jetPt*part1 + part0h)*(pow(jeteta,2)*etapart+1); 


	double rateL  = (par1*jetPt + par2*jetPt*jetPt + par0)*(pow(jeteta,2)*etaparl+1); 
	double rateLl = (par1*jetPt + par2*jetPt*jetPt + par0l)*(pow(jeteta,2)*etaparl+1); 
	double rateLh = (par1*jetPt + par2*jetPt*jetPt + par0h)*(pow(jeteta,2)*etaparl+1); 









	double lr = rr.Rndm();
	double tr = rr.Rndm();

	if(lr < rateL ){
	  if(islij == 0) il1 =1; 
	  if(ij == 1) il2 =1; 
	  if(ij == 2) il3 =1; 
	  isl++; 
	  if(tr < rateT ){
	    ist++;
	    if(ij == 0) it1 =1; 
	    if(ij == 1) it2 =1; 
	    if(ij == 2) it3 =1; 
	  }
	}

	
	if(lr < rateLl ){
	  isll++; 
	  if(tr < rateTl ) istl++;	  
	}


	if(lr < rateLh ){
	  islh++; 
	  if(tr < rateTh ) isth++;	  
	}



	TVector3 jv1,jv2; 
	float jpt = (*ak8pt)[ij]; 
	float jphi = (*ak8phi)[ij]; 
	float jeta = (*ak8eta)[ij]; 
	float mindr = 99; 
	jv1.SetPtEtaPhi(jpt,jeta,jphi);
	for(ijk = 0; ijk < jsize; ijk++){
	  if(ijk == ij) continue; 

	  float jpt = (*ak8pt)[ijk]; 
	  float jphi = (*ak8phi)[ijk]; 
	  float jeta = (*ak8eta)[ijk]; 
	  jv2.SetPtEtaPhi(jpt,jeta,jphi);
	  float dr = jv1.DeltaR(jv2);
	  if(dr < mindr) mindr = dr; 
	}
	
	if( ij == 1) mindr1 = mindr;
	if( ij == 2) mindr2 = mindr;
	if( ij == 3) mindr2 = mindr;
      }
      



      if(isl == 0){
 	float m1 = (*ak8m)[0]; 
	float m2 = (*ak8m)[1]; 
	float m3 = (*ak8m)[2]; 

	LT00M->Fill(m1); LT00M->Fill(m2); LT00M->Fill(m3);
	float mav = (m1+m2+m3) /3.0;
	LT00Mav->Fill(mav);
	LT00ht->Fill(HTak4);

      }
      
      if(isl == 1 && ist == 0){
	
	float m = 0; 
	if(il1 == 1 ) m = (*ak8m)[0]; 
	if(il2 == 1 ) m = (*ak8m)[1]; 
	if(il3 == 1 ) m = (*ak8m)[2]; 

	if(m == 0 ) cout<<"warning l"<<il1+il2+il3<<endl;

	LT10M->Fill(m);
	LT10ht->Fill(HTak4);

      }

      if(isl == 1 && ist == 1){
	float m = 0; 
	if(it1 == 1 ) m = (*ak8m)[0]; 
	if(it2 == 1 ) m = (*ak8m)[1]; 
	if(it3 == 1 ) m = (*ak8m)[2]; 

	if(m == 0 ) cout<<"warning t "<< it1 +it2+it3<<endl;

	LT11M->Fill(m);
	LT11ht->Fill(HTak4);

      }
      
      if(isl == 2 && ist == 0 ){
	float m1 = 0; float m2 = 0;

  
	if(il1 == 1 && il2 == 1 ) {
	  m1 = (*ak8m)[0]; 
	  m2 = (*ak8m)[1];
	  LT20dr->Fill(mindr1);
	  LT20dr->Fill(mindr2);
	  

	}
	if(il1 == 1 && il3 == 1 ) {
	  m1 = (*ak8m)[0]; 
	  m2 = (*ak8m)[2];
	  LT20dr->Fill(mindr1);
	  LT20dr->Fill(mindr3);

	}
	if(il2 == 1 && il3 == 1 ) {
	  m1 = (*ak8m)[1]; 
	  m2 = (*ak8m)[2];

	  LT20dr->Fill(mindr2);
	  LT20dr->Fill(mindr3);
	}
	LT20M->Fill(m1);
	LT20M->Fill(m2);
	float mh = 0; 
	if(m1 > m2) mh = m1; 
	if(m2 > m1) mh = m2; 
	float mav = (m1+m2)/2.0;
	LT20Mav->Fill(mav);
	LT20M_2d->Fill(m1,m2);
	LT20ht->Fill(HTak4);	
	LT20m_ht->Fill(HTak4,mh);
      }

      if(isl == 2 && ist == 1 ){
	float ml = 0; 
	float mt = 0; 
	
	
	if(it1 == 1)LT21dr->Fill(mindr1);
	if(it2 == 1)LT21dr->Fill(mindr2);
	if(it3 == 1)LT21dr->Fill(mindr3);
		
	if(il1 == 1 && it1 == 1 ) mt = (*ak8m)[0];
	if(il1 == 1 && it1 == 0 ) ml = (*ak8m)[0];
	if(il2 == 1 && it2 == 1 ) mt = (*ak8m)[1];
	if(il2 == 1 && it2 == 0 ) ml = (*ak8m)[1];
	if(il3 == 1 && it3 == 1 ) mt = (*ak8m)[2];
	if(il3 == 1 && it3 == 0 ) ml = (*ak8m)[2];
	float mav = 0.5*(mt+ml);

	float mh = 0; 
	if(mt > ml) mh = mt; 
	if(ml > mt) mh = ml; 


	LT21M->Fill(ml);
	LT21M->Fill(mt);
	LT21MT->Fill(mt);
	LT21Mav->Fill(mav);
	LT21M_2d->Fill(mt,ml);
	LT21ht->Fill(HTak4);
	LT21m_ht->Fill(HTak4,mh);
      }

      if(isl == 2 && ist == 2){
	float m1 = 0; 
	float m2 = 0; 
	
	if( it1 == 1 && it2 == 1){
	  m1 = (*ak8m)[0];
	  m2 = (*ak8m)[1];

	  LT22dr->Fill(mindr1);
	  LT22dr->Fill(mindr2);
	}
	if( it1 == 1 && it3 == 1){
	  m1 = (*ak8m)[0];
	  m2 = (*ak8m)[2];
	  LT22dr->Fill(mindr1);
	  LT22dr->Fill(mindr3);
	  
	}
	if( it2 == 1 && it3 == 1){
	  m1 = (*ak8m)[1];
	  m2 = (*ak8m)[2];
	  LT22dr->Fill(mindr2);
	  LT22dr->Fill(mindr3);

	}
	LT22M->Fill(m1); LT22M->Fill(m2);
	float mav = 0.5*(m1+m2); 
	LT22Mav->Fill(mav);
	LT22M_2d->Fill(m1,m2);
	LT22ht->Fill(HTak4);
	float mh= 0; 
	if(m1 > m2)mh = m1; 
	if(m2 > m1)mh = m2; 
	LT22m_ht->Fill(HTak4,mh);
      }





      //Need to do so for high

      if(islh == 0){
 	float m1 = (*ak8m)[0]; 
	float m2 = (*ak8m)[1]; 
	float m3 = (*ak8m)[2]; 

	LT00Mh->Fill(m1); LT00Mh->Fill(m2); LT00Mh->Fill(m3);
	float mav = (m1+m2+m3) /3.0;
	LT00Mavh->Fill(mav);
	LT00hth->Fill(HTak4);

      }
      
      if(islh == 1 && isth == 0){
	float m = 0; 
	if(il1h == 1 ) m = (*ak8m)[0]; 
	if(il2h == 1 ) m = (*ak8m)[1]; 
	if(il3h == 1 ) m = (*ak8m)[2]; 

	LT10Mh->Fill(m);
	LT10hth->Fill(HTak4);

      }

      if(islh == 1 && isth == 1){
	float m = 0; 
	if(it1h == 1 ) m = (*ak8m)[0]; 
	if(it2h == 1 ) m = (*ak8m)[1]; 
	if(it3h == 1 ) m = (*ak8m)[2]; 

	LT11Mh->Fill(m);
	LT11hth->Fill(HTak4);

      }
      
      if(islh == 2 && isth == 0 ){
	float m1 = 0; float m2 = 0;  
	if(il1h == 1 && il2h == 1 ) {
	  m1 = (*ak8m)[0]; 
	  m2 = (*ak8m)[1];
	}
	if(il1h == 1 && il3h == 1 ) {
	  m1 = (*ak8m)[0]; 
	  m2 = (*ak8m)[2];
	}
	if(il2h == 1 && il3h == 1 ) {
	  m1 = (*ak8m)[1]; 
	  m2 = (*ak8m)[2];
	}
	LT20Mh->Fill(m1);
	LT20Mh->Fill(m2);
	float mh = 0; 
	if(m1 > m2) mh = m1; 
	if(m2 > m1) mh = m2; 
	float mav = (m1+m2)/2.0;
	LT20Mavh->Fill(mav);
	LT20M_2dh->Fill(m1,m2);
	LT20hth->Fill(HTak4);	
	LT20m_hth->Fill(HTak4,mh);
      }

      if(islh == 2 && isth == 1 ){
	float ml = 0; 
	float mt = 0; 
	
	if(il1h == 1 && it1h == 1 ) mt = (*ak8m)[0];
	if(il1h == 1 && it1h == 0 ) ml = (*ak8m)[0];
	if(il2h == 1 && it2h == 1 ) mt = (*ak8m)[1];
	if(il2h == 1 && it2h == 0 ) ml = (*ak8m)[1];
	if(il3h == 1 && it3h == 1 ) mt = (*ak8m)[2];
	if(il3h == 1 && it3h == 0 ) ml = (*ak8m)[2];
	float mav = 0.5*(mt+ml);

	float mh = 0; 
	if(mt > ml) mh = mt; 
	if(ml > mt) mh = ml; 


	LT21Mh->Fill(ml);
	LT21Mh->Fill(mt);
	LT21MTh->Fill(mt);
	LT21Mavh->Fill(mav);
	LT21M_2dh->Fill(mt,ml);
	LT21hth->Fill(HTak4);
	LT21m_hth->Fill(HTak4,mh);
      }

      if(islh == 2 && isth == 2){
	float m1 = 0; 
	float m2 = 0; 
	
	if( it1h == 1 && it2h == 1){
	  m1 = (*ak8m)[0];
	  m2 = (*ak8m)[1];
	}
	if( it1h == 1 && it3h == 1){
	  m1 = (*ak8m)[0];
	  m2 = (*ak8m)[2];
	}
	if( it2h == 1 && it3h == 1){
	  m1 = (*ak8m)[1];
	  m2 = (*ak8m)[2];
	}
	LT22Mh->Fill(m1); LT22Mh->Fill(m2);
	float mav = 0.5*(m1+m2); 
	LT22Mavh->Fill(mav);
	LT22M_2dh->Fill(m1,m2);
	LT22hth->Fill(HTak4);
	float mh= 0; 
	if(m1 > m2)mh = m1; 
	if(m2 > m1)mh = m2; 
	LT22m_hth->Fill(HTak4,mh);
      }


      if(isll == 0 ){
	LT10htl->Fill(HTak4);
      }

      if(isll == 1 && istl == 0 ){
	LT10htl->Fill(HTak4);
      }


      if(isll == 1 && istl == 1 ){
	LT11htl->Fill(HTak4);

      }

      if(isll == 2 && istl == 0){
	LT20htl->Fill(HTak4);

      }
      
      if(isll == 2 && istl == 1){
	LT21htl->Fill(HTak4);
      }

      if(isll == 2 && istl == 2){
	LT22htl->Fill(HTak4);
      }


      //Need to do so for low




      
      NJLTen->Fill(ist,isl);
      NJLTenh->Fill(isth,islh);
      NJLTenl->Fill(istl,isll);
    }
    
  }
  
  NJLTen->Scale(1./itries);
  NJLTenh->Scale(1./itries);
  NJLTenl->Scale(1./itries);
  
  LT20dr->Scale(1./itries);
  LT21dr->Scale(1./itries);
  LT22dr->Scale(1./itries);


  LT00M->Scale(1./itries);
  LT10M->Scale(1./itries);
  LT11M->Scale(1./itries);
  LT20M->Scale(1./itries);
  LT21M->Scale(1./itries);
  LT21MT->Scale(1./itries);
  LT22M->Scale(1./itries);

  LT00Mav->Scale(1./itries);
  LT20Mav->Scale(1./itries);
  LT21Mav->Scale(1./itries);
  LT22Mav->Scale(1./itries);

  LT20M_2d->Scale(1./itries);
  LT21M_2d->Scale(1./itries);
  LT22M_2d->Scale(1./itries);


  LT20ht->Scale(1./itries);
  LT21ht->Scale(1./itries);
  LT22ht->Scale(1./itries);

  LT10ht->Scale(1./itries);
  LT11ht->Scale(1./itries);
  LT00ht->Scale(1./itries);


  LT20htl->Scale(1./itries);
  LT21htl->Scale(1./itries);
  LT22htl->Scale(1./itries);

  LT10htl->Scale(1./itries);
  LT11htl->Scale(1./itries);
  LT00htl->Scale(1./itries);

  LT22m_ht->Scale(1./itries);
  LT21m_ht->Scale(1./itries);
  LT20m_ht->Scale(1./itries);


  // high ones
  LT00Mh->Scale(1./itries);
  LT10Mh->Scale(1./itries);
  LT11Mh->Scale(1./itries);
  LT20Mh->Scale(1./itries);
  LT21Mh->Scale(1./itries);
  LT21MTh->Scale(1./itries);
  LT22Mh->Scale(1./itries);

  LT00Mavh->Scale(1./itries);
  LT20Mavh->Scale(1./itries);
  LT21Mavh->Scale(1./itries);
  LT22Mavh->Scale(1./itries);

  LT20M_2dh->Scale(1./itries);
  LT21M_2dh->Scale(1./itries);
  LT22M_2dh->Scale(1./itries);


  LT20hth->Scale(1./itries);
  LT21hth->Scale(1./itries);
  LT22hth->Scale(1./itries);

  LT10hth->Scale(1./itries);
  LT11hth->Scale(1./itries);
  LT00hth->Scale(1./itries);

  LT22m_hth->Scale(1./itries);
  LT21m_hth->Scale(1./itries);
  LT20m_hth->Scale(1./itries);


  //Scaling and saving                                             

  TH1D *LT00M_sc  = LT00M->Clone();
  TH1D *LT10M_sc  = LT10M->Clone();
  TH1D *LT11M_sc  = LT11M->Clone();
  TH1D *LT20M_sc  = LT20M->Clone();
  TH1D *LT21M_sc  = LT21M->Clone();
  TH1D *LT21MT_sc = LT21MT->Clone();
  TH1D *LT22M_sc  = LT22M->Clone();
  TH1D *LT20ht_sc = LT20ht->Clone();
  TH1D *LT21ht_sc = LT21ht->Clone();
  TH1D *LT22ht_sc = LT22ht->Clone();
  TH1D *LT10ht_sc = LT10ht->Clone();
  TH1D *LT11ht_sc = LT11ht->Clone();
  TH1D *LT00ht_sc = LT00ht->Clone();

  TH1D *LT20Mav_sc  = LT20Mav->Clone();
  TH1D *LT21Mav_sc  = LT21Mav->Clone();
  TH1D *LT22Mav_sc  = LT22Mav->Clone();



 
  LT00M_sc->SetName("LT00M_sc");
  LT10M_sc->SetName("LT10M_sc");
  LT11M_sc->SetName("LT11M_sc");
  LT20M_sc->SetName("LT20M_sc");
  LT21M_sc->SetName("LT21M_sc");
  LT21MT_sc->SetName("LT21MT_sc");
  LT22M_sc->SetName("LT22M_sc");
  LT20ht_sc->SetName("LT20ht_sc");
  LT21ht_sc->SetName("LT21ht_sc");
  LT22ht_sc->SetName("LT22ht_sc");
  LT10ht_sc->SetName("LT10ht_sc");
  LT11ht_sc->SetName("LT11ht_sc");
  LT00ht_sc->SetName("LT00ht_sc");

  LT20Mav_sc->SetName("LT20Mav_sc");
  LT21Mav_sc->SetName("LT21Mav_sc");
  LT22Mav_sc->SetName("LT22Mav_sc");



  //High ones 
  //Scaling and saving 
  TH1D *LT00M_sch  = LT00Mh->Clone();
  TH1D *LT10M_sch  = LT10Mh->Clone();
  TH1D *LT11M_sch  = LT11Mh->Clone();
  TH1D *LT20M_sch  = LT20Mh->Clone();
  TH1D *LT21M_sch  = LT21Mh->Clone();
  TH1D *LT21MT_sch = LT21MTh->Clone();
  TH1D *LT22M_sch  = LT22Mh->Clone();
  TH1D *LT20ht_sch = LT20hth->Clone();
  TH1D *LT21ht_sch = LT21hth->Clone();
  TH1D *LT22ht_sch = LT22hth->Clone();
  TH1D *LT10ht_sch = LT10hth->Clone();
  TH1D *LT11ht_sch = LT11hth->Clone();
  TH1D *LT00ht_sch = LT00hth->Clone();

  TH1D *LT20Mav_sch  = LT20Mavh->Clone();
  TH1D *LT21Mav_sch  = LT21Mavh->Clone();
  TH1D *LT22Mav_sch  = LT22Mavh->Clone();



  
  LT00M_sch->SetName("LT00M_sch");
  LT10M_sch->SetName("LT10M_sch");
  LT11M_sch->SetName("LT11M_sch");
  LT20M_sch->SetName("LT20M_sch");
  LT21M_sch->SetName("LT21M_sch");
  LT21MT_sch->SetName("LT21MT_sch");
  LT22M_sch->SetName("LT22M_sch");
  LT20ht_sch->SetName("LT20ht_sch");
  LT21ht_sch->SetName("LT21ht_sch");
  LT22ht_sch->SetName("LT22ht_sch");
  LT10ht_sch->SetName("LT10ht_sch");
  LT11ht_sch->SetName("LT11ht_sch");
  LT00ht_sch->SetName("LT00ht_sch");

  LT20Mav_sch->SetName("LT20Mav_sch");
  LT21Mav_sch->SetName("LT21Mav_sch");
  LT22Mav_sch->SetName("LT22Mav_sch");



  float xsec115  = 1206.0;
  float xsec152  = 120.4;
  float xsec2inf = 25.25;
  int ntot115 = 10221142; 
  int ntot152 = 10436288; 
  int ntot2inf = 4579491; 

  double scale = 30.0*1000.0*xsec115/ntot115;
  LT00M_sc->Scale(scale);
  LT10M_sc->Scale(scale);
  LT11M_sc->Scale(scale);
  LT20M_sc->Scale(scale);
  LT21M_sc->Scale(scale);
  LT21MT_sc->Scale(scale);
  LT22M_sc->Scale(scale);
  LT20ht_sc->Scale(scale);
  LT21ht_sc->Scale(scale);
  LT22ht_sc->Scale(scale);
  LT10ht_sc->Scale(scale);
  LT11ht_sc->Scale(scale);
  LT00ht_sc->Scale(scale);


  LT20Mav_sc->Scale(scale);
  LT21Mav_sc->Scale(scale);
  LT22Mav_sc->Scale(scale);




  LT00M_sch->Scale(scale);
  LT10M_sch->Scale(scale);
  LT11M_sch->Scale(scale);
  LT20M_sch->Scale(scale);
  LT21M_sch->Scale(scale);
  LT21MT_sch->Scale(scale);
  LT22M_sch->Scale(scale);
  LT20ht_sch->Scale(scale);
  LT21ht_sch->Scale(scale);
  LT22ht_sch->Scale(scale);
  LT10ht_sch->Scale(scale);
  LT11ht_sch->Scale(scale);
  LT00ht_sch->Scale(scale);


  LT20Mav_sch->Scale(scale);
  LT21Mav_sch->Scale(scale);
  LT22Mav_sch->Scale(scale);






  ostringstream btc; 
  btc << ibatch; 
  
  string fout ="./Plots/Ensemble_"+btc.str()+"_Rates_PL.root"; 
  const char *foutc = fout.c_str(); 
  
  TFile *f2 = new TFile(foutc,"recreate");
  f2->cd();

  L0->Write();
  L1->Write();
  T1->Write();
  LR->Write();
  TR->Write();
  NJLT->Write();
  NJLTen->Write();
  NJLTenl->Write();
  NJLTenh->Write();
  
  LT00M->Write();
  LT10M->Write();
  LT11M->Write();
  LT20M->Write();
  LT21M->Write();
  LT21MT->Write();
  LT22M->Write();

  LT00Mc->Write();
  LT10Mc->Write();
  LT11Mc->Write();
  LT20Mc->Write();
  LT21Mc->Write();
  LT21MTc->Write();
  LT22Mc->Write();



  LT00Mav->Write();
  LT20Mav->Write();
  LT21Mav->Write();
  LT22Mav->Write();

  LT20M_2d->Write();
  LT21M_2d->Write();
  LT22M_2d->Write();


  LT20ht->Write();
  LT21ht->Write();
  LT22ht->Write();

  LT10ht->Write();
  LT11ht->Write();
  LT00ht->Write();

  LT22m_ht->Write();
  LT21m_ht->Write();
  LT20m_ht->Write();
  
  //High rate plots
  LT00Mh->Write();
  LT10Mh->Write();
  LT11Mh->Write();
  LT20Mh->Write();
  LT21Mh->Write();
  LT21MTh->Write();
  LT22Mh->Write();

  LT00Mavh->Write();
  LT20Mavh->Write();
  LT21Mavh->Write();
  LT22Mavh->Write();

  LT20M_2dh->Write();
  LT21M_2dh->Write();
  LT22M_2dh->Write();


  LT10htl->Write();
  LT11htl->Write();
  LT00htl->Write();
  LT20htl->Write();
  LT21htl->Write();
  LT22htl->Write();
 



  LT20hth->Write();
  LT21hth->Write();
  LT22hth->Write();

  LT10hth->Write();
  LT11hth->Write();
  LT00hth->Write();

  LT22m_hth->Write();
  LT21m_hth->Write();
  LT20m_hth->Write();
  




  // Scale Normal rate

  LT00M_sc->Write();
  LT10M_sc->Write();
  LT11M_sc->Write();
  LT20M_sc->Write();
  LT21M_sc->Write();
  LT21MT_sc->Write();
  LT22M_sc->Write();
  LT20ht_sc->Write();
  LT21ht_sc->Write();
  LT22ht_sc->Write();
  LT10ht_sc->Write();
  LT11ht_sc->Write();
  LT00ht_sc->Write();
  LT20Mav_sc->Write();
  LT21Mav_sc->Write();
  LT22Mav_sc->Write();



  LT00M_sch->Write();
  LT10M_sch->Write();
  LT11M_sch->Write();
  LT20M_sch->Write();
  LT21M_sch->Write();
  LT21MT_sch->Write();
  LT22M_sch->Write();
  LT20ht_sch->Write();
  LT21ht_sch->Write();
  LT22ht_sch->Write();
  LT10ht_sch->Write();
  LT11ht_sch->Write();
  LT00ht_sch->Write();
  LT20Mav_sch->Write();
  LT21Mav_sch->Write();
  LT22Mav_sch->Write();


  LT20htc->Write();
  LT21htc->Write();
  LT22htc->Write();
  LT10htc->Write();
  LT11htc->Write();
  LT00htc->Write();

 
  LT22dr->Write();
  LT20dr->Write();
  LT21dr->Write();

  LT22drc->Write();
  LT20drc->Write();
  LT21drc->Write();

  
}
