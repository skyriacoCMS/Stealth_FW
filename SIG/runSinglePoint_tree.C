#include <TH1F.h>
#include <TH2D.h>
#include <TMath.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <TVector3.h>
#include <TTree.h>
#include "sstream"
#include <string>
#include <TFile.h>
#include <CUTS.C>


void runSinglePoint_tree(int ib){

  int i = 0; 




  int chizeromass[10] = {113,125,150,175,200,300,400,500,600,700};
  int gluinomass[16]  = {1000,1050,1100,1150,1200,1250,1300,1350,1400,1450,1500,1550,1600,1650,1700,1750};

  
  //  for(int i = 0;  i < 32; i++){
  
  
  int i  = 4; 
    int imchi = i % 10; 
    int imglu  = i/10;
    int mchi = chizeromass[imchi]; 
    int mglu = gluinomass[imglu];
    
    cout<<"mchi :"<<mchi <<" mgl "<<mglu<<endl;
    
    float xss;
    xss = xsec(imglu);
    CUTS(ib,4,mchi,mglu,xss); 
    // }

    i  = 2; 
   imchi = i % 10; 
   imglu  = i/10;
   mchi = chizeromass[imchi]; 
   mglu = gluinomass[imglu];
    
    cout<<"mchi :"<<mchi <<" mgl "<<mglu<<endl;
    
    float xss;
    xss = xsec(imglu);
    CUTS(ib,4,mchi,mglu,xss); 
   

   i  = 6; 
   imchi = i % 10; 
   imglu  = i/10;
   mchi = chizeromass[imchi]; 
   mglu = gluinomass[imglu];
    
    cout<<"mchi :"<<mchi <<" mgl "<<mglu<<endl;
    
    float xss;
    xss = xsec(imglu);
    CUTS(ib,4,mchi,mglu,xss); 



   i  = 8; 
   imchi = i % 10; 
   imglu  = i/10;
   mchi = chizeromass[imchi]; 
   mglu = gluinomass[imglu];
    
    cout<<"mchi :"<<mchi <<" mgl "<<mglu<<endl;
    
    //    float xss;
    xss = xsec(imglu);
    CUTS(ib,4,mchi,mglu,xss); 
   



}

float xsec( int i){

  float a[19]={0.325388,0.229367,0.163491,0.117687,0.0856418,0.0627027,0.0460525,0.0340187,0.0252977,0.0188887,0.0141903,0.0107027,0.00810078,0.00616072,0.00470323,0.00359842,0.00276133,0.00212345,0.00163547};
  
  if(i > 15) return 0; 
  
  return a[i];

}





/*
int is_Loose(float haspho,float t3t1,float haspixel,float phoeta,float phosie,float phohoe ){
  if(haspho == -99) return 0;
  if(haspixel == 0 && haspho && t3t1 < 0.5 ){
    //    return 1; 
    if(fabs(phoeta) < 1.4789 && phosie < 0.019 && phohoe < 0.05) return 1; 
    if(fabs(phoeta) > 1.4789 && phosie < 0.03 && phohoe < 0.05) return 1; 
  }
  return 0; 
}


int is_Tight(float haspho,float t3t1,float haspixel,float subjf,float phoeta,float phosie,float phohoe ){
  if(haspho == -99 ) return 0; 
  if(haspixel == 0 && haspho && t3t1 < 0.5 && subjf > 0.8 ){
    //return 1; 
    if(fabs(phoeta) < 1.4789 && phosie < 0.019 && phohoe < 0.05) return 1; 
    if(fabs(phoeta) > 1.4789 && phosie < 0.03 && phohoe < 0.05) return 1; 
  }
  return 0; 
}


void CUTS(int mchi,int mglu,float xss){

  TFile *f12 = new TFile("../../../../Trees/sig.root");
  f12->cd(); 
  demo->cd();

  TH2D *NJLT    = new TH2D("NJLT","",5,0,5,5,0,5);
  TH1F *NJ_all    = new TH1F("NJ_all","",20,0,10);

  TH1F *L0     = new TH1F("L0","",45,200,2000); //,10,-5,5);                    
  TH1F *L1     = new TH1F("L1","",45,200,2000); //,10,-5,5);                    
  TH2F *ChiS   = new TH2F("ChiS","",2000,0,2000,2000,0,2000);

  
  TH1F *L11    = new TH1F("L11","",45,200,2000); //,10,-5,5);                    
  TH1F *T1     = new TH1F("T1","",45,200,2000); //,10,-5,5);                    
  TH1F *TR     = new TH1F("TR","",45,200,2000); //,10,-5,5);                    
  TH1F *LR     = new TH1F("LR","",45,200,2000); //,10,-5,5);              

  TH1F *LM     = new TH1F("LM","",50,0,1000); //,10,-5,5);              
  TH1F *TM     = new TH1F("TM","",50,0,1000); //,10,-5,5);              
  TH1F *L2M     = new TH1F("L2M","",50,0,1000); //,10,-5,5);              
  
  
  TH1F *LT00M  = new TH1F("LT00M","",50,0,1000); //,10,-5,5);              
  TH1F *LT10M  = new TH1F("LT10M","",50,0,1000); //,10,-5,5);              
  TH1F *LT11M  = new TH1F("LT11M","",50,0,1000); //,10,-5,5);              
  TH1F *LT20M  = new TH1F("LT20M","",50,0,1000); //,10,-5,5);              
  TH1F *LT21M  = new TH1F("LT21M","",50,0,1000); //,10,-5,5);              
  TH1F *LT21MT = new TH1F("LT21MT","",50,0,1000); //,10,-5,5);              
  TH1F *LT22M  = new TH1F("LT22M","",50,0,1000); //,10,-5,5);              

  TH1F *LT00Mav  = new TH1F("LT00Mav","",50,0,1000); //,10,-5,5);                        
  TH1F *LT20Mav  = new TH1F("LT20Mav","",50,0,1000); //,10,-5,5);                        
  TH1F *LT21Mav  = new TH1F("LT21Mav","",50,0,1000); //,10,-5,5);                        
  TH1F *LT22Mav  = new TH1F("LT22Mav","",50,0,1000); //,10,-5,5);       

  TH2F *LT20M_2d  = new TH2F("LT20M_2d","",50,0,1000,50,0,1000);
  TH2F *LT21M_2d  = new TH2F("LT21M_2d","",50,0,1000,50,0,1000);
  TH2F *LT22M_2d  = new TH2F("LT22M_2d","",50,0,1000,50,0,1000);

  TH1F * mas22 = new TH1F("mas22","",100,0,2);

  TH2F *LT22m_ht   = new TH2F("LT22m_ht","",30,1000,4000,50,0,1000);
  TH2F *LT21m_ht   = new TH2F("LT21m_ht","",30,1000,4000,50,0,1000);
  TH2F *LT20m_ht   = new TH2F("LT20m_ht","",30,1000,4000,50,0,1000);


                                                                             
  TH1F *h_t31      = new TH1F("h_t31","",100,0,1);                           
  TH1F *h_haspho   = new TH1F("h_haspho","",18,-1,2);                         
  TH1F *h_subjf    = new TH1F("h_subjf","",300,-1,2);                         
  TH1F *h_subjfO    = new TH1F("h_subjfO","",300,-1,2);                         
                                                                             
  TH1F *h_phosieieB    = new TH1F("h_phosieieB","",500,0,0.015);             
  TH1F *h_phosieieE    = new TH1F("h_phosieieE","",300,0.02,0.03);               TH1F *h_phopt      = new TH1F("h_phopt","",100,0,1000);
 
  TH1F *h_phohoe      = new TH1F("h_phohoe","",100,0,0.15);                  
  TH1F *h_phohaspix   = new TH1F("h_phohaspix","",100,-1,2);                  

  TH1F *h_spt1   = new TH1F("h_spt1","",100,0,1000);
  TH1F *h_spt2   = new TH1F("h_spt2","",100,0,1000);
  TH1F *h_spt3   = new TH1F("h_spt3","",100,0,1000);


  TH1F *h_phopt_m      = new TH1F("h_phopt_m","",100,0,1000);
  TH1F *h_t31_m      = new TH1F("h_t31_m","",100,0,1);
  TH1F *h_haspho_m   = new TH1F("h_haspho_m","",18,-1,2);
  TH1F *h_subjf_m    = new TH1F("h_subjf_m","",300,-1,2);
  TH1F *h_subjfO_m    = new TH1F("h_subjfO_m","",300,-1,2);
  TH1F *h_phosieieB_m    = new TH1F("h_phosieieB_m","",500,0,0.015);
  TH1F *h_phosieieE_m    = new TH1F("h_phosieieE_m","",300,0.02,0.03);
  TH1F *h_phohoe_m      = new TH1F("h_phohoe_m","",100,0,0.15);
  TH1F *h_phohaspix_m   = new TH1F("h_phohaspix_m","",100,-1,2);
  TH1F *h_spt1_m   = new TH1F("h_spt1_m","",100,0,1000);
  TH1F *h_spt2_m   = new TH1F("h_spt2_m","",100,0,1000);
  TH1F *h_spt3_m   = new TH1F("h_spt3_m","",100,0,1000);




  TH1F *LT20ht     = new TH1F("LT20ht","",30,1000,4000);
  TH1F *LT21ht     = new TH1F("LT21ht","",30,1000,4000);
  TH1F *LT22ht     = new TH1F("LT22ht","",30,1000,4000);

  TH1F *LT10ht     = new TH1F("LT10ht","",30,1000,4000);
  TH1F *LT11ht     = new TH1F("LT11ht","",30,1000,4000);
  TH1F *LT00ht     = new TH1F("LT00ht","",30,1000,4000);



  // Setting the output file
  ostringstream mch; 
  ostringstream mgl; 
  mch<<mchi;
  mgl<<mglu;
  string fou = "./PlotsNJ3/chi_"+mch.str()+"glu_"+mgl.str()+"new.root"; 
  string fou_plot = "./PlotsNJ3/chi_"+mch.str()+"glu_"+mgl.str()+"new.png"; 
  string fou_tree = "./PlotsNJ3/jetTreeNj3_"+mch.str()+"glu_"+mgl.str()+"new.root"; 
  const char *outF = fou.c_str();
  const char *outFp = fou_plot.c_str();
  const char *outFt = fou_tree.c_str();



  TFile *f2 = new TFile(outFt,"recreate");
  TTree *ev =  new TTree("ev","treeofJets"); 
  
  vector<int> isLoose; 
  vector<int> isTight; 
  vector<float> ak8pt; 
  vector<float> ak8phi; 
  vector<float> ak8eta; 
  vector<float> ak8m; 
  vector<int>   phoindx;
  float htak4;
  

  ev->Branch("htak4",&htak4,"htak4/F");
  ev->Branch("isLoose",&isLoose);
  ev->Branch("isTight",&isTight);
  ev->Branch("ak8pt",&ak8pt);
  ev->Branch("ak8phi",&ak8phi);
  ev->Branch("ak8eta",&ak8eta);
  ev->Branch("ak8m",&ak8m);
  ev->Branch("phoindx",&phoindx);

  f12->cd();
  demo->cd();
  int NJ; 
  float HTak4; 

  L0->Sumw2(); 
  T1->Sumw2(); 
  L1->Sumw2(); 
  L11->Sumw2();
  
  LR->Sumw2(); 
  TR->Sumw2(); 

  vector<float> *ak8ptC; 
  vector<float> *ak8phiC; 
  vector<float> *ak8etaC; 
  vector<float> *ak8t3t1C;
  vector<float> *ak8subjC;
  vector<float> *ak8phoindxC; 
  vector<float> *ak8prMassC; 
  

  //photon quantites

  vector<float> *phopt; 
  vector<float> *phoeta; 
  vector<float> *phophi; 
  vector<float> *phohoe; 
  vector<float> *phosieie; 
  vector<float> *phohaspixelseed; 

  //mcquantities
  float mcglumass; 
  float mcchimass; 

  vector<float> *mcchipt;
  vector<float> *mcchieta;
  vector<float> *mcchiphi;
  vector<float> *ak8spt1;
  vector<float> *ak8spt2;
  vector<float> *ak8spt3;
  
    
  event->SetBranchAddress("NJ",&NJ);
  event->SetBranchAddress("HTak4",&HTak4);

  event->SetBranchAddress("ak8spt1",&ak8spt1);
  event->SetBranchAddress("ak8spt2",&ak8spt2);
  event->SetBranchAddress("ak8spt3",&ak8spt3);

  event->SetBranchAddress("ak8ptC",&ak8ptC);
  event->SetBranchAddress("ak8etaC",&ak8etaC);
  event->SetBranchAddress("ak8phiC",&ak8phiC);
  event->SetBranchAddress("ak8t3t1C",&ak8t3t1C); 
  event->SetBranchAddress("ak8subjC",&ak8subjC); 
  event->SetBranchAddress("ak8phoindxC",&ak8phoindxC);
  event->SetBranchAddress("ak8prMassC",&ak8prMassC);

  event->SetBranchAddress("phopt",&phopt); 
  event->SetBranchAddress("phoeta",&phoeta); 
  event->SetBranchAddress("phophi",&phophi); 
  event->SetBranchAddress("phohoe",&phohoe); 
  event->SetBranchAddress("phosieie",&phosieie); 
  event->SetBranchAddress("phohaspixelseed",&phohaspixelseed); 
 
  
  event->SetBranchAddress("mcglumass",&mcglumass); 
  event->SetBranchAddress("mcchimass",&mcchimass);
  event->SetBranchAddress("mcchipt",&mcchipt);
  event->SetBranchAddress("mcchieta",&mcchieta);
  event->SetBranchAddress("mcchiphi",&mcchiphi);


  int entt =  event->GetEntries();
  for(int i  = 0; i < entt;   i++){
    event->GetEntry(i);
    
    //    ChiS->Fill(mcchimass,mcglumass);


    //    if( (mcglumass - mcchimass) < 900 ) continue; 
    
    //Rejecting other mass points
    if(mcglumass < mglu - 20 || mcglumass >  mglu + 20 ) continue; 
    if(mcchimass  >= 150){
      if( mcchimass < mchi  - 10  || mcchimass >  mchi + 10 ) continue;
    } else{
      if( mcchimass < mchi  - 5  || mcchimass >  mchi + 5   ) continue;
    }
  
    NJ_all->Fill(NJ);
    if(NJ != 3  || HTak4 < 1000 ) continue; 
    if(i % 10000 == 0 ) cout<<"entry: "<<i <<" "<<entt<<endl;

    isLoose.clear(); 
    isTight.clear(); 
    ak8pt.clear(); 
    ak8phi.clear(); 
    ak8eta.clear(); 
    ak8m.clear();
    phoindx.clear();


    TVector3 jv1,jv2,jv3;
    float pt1  =  (*ak8ptC)[0];  float pt2  =  (*ak8ptC)[1];  float pt3  =  (*ak8ptC)[2];
    float phi1 =  (*ak8phiC)[0]; float phi2 =  (*ak8phiC)[1]; float phi3 =  (*ak8phiC)[2];
    float eta1 =  (*ak8etaC)[0]; float eta2 =  (*ak8etaC)[1]; float eta3 =  (*ak8etaC)[2];

    jv1.SetPtEtaPhi(pt1,eta1,phi1);
    jv2.SetPtEtaPhi(pt2,eta2,phi2);
    jv3.SetPtEtaPhi(pt3,eta3,phi3);


    float dr12 = jv1.DeltaR(jv2);
    float dr13 = jv1.DeltaR(jv3);
    float dr32 = jv3.DeltaR(jv2);
    if(dr12 < 1.6 || dr13 < 1.6 || dr32 < 1.6 ) continue;


    htak4 = HTak4; 

    int it = 0; 
    int il = 0; 
    vector<int> phoI;
    phoI.clear();

    for(int ij = 0; ij < (*ak8ptC).size(); ij++){
      float jetpt  = (*ak8ptC)[ij];
      float jeteta = (*ak8etaC)[ij];
      float jetphi = (*ak8etaC)[ij];
      int   phoind = int( (*ak8phoindxC)[ij] );
      float t3t1  = (*ak8t3t1C)[ij];

      bool matchi = false;

      TVector3 jv;
      jv.SetPtEtaPhi(jetpt,jeteta,jetphi);

      for(int ichii = 0; ichii < (*mcchipt).size(); ichii++){
        float cpt  = (*mcchipt)[ichii];
	float ceta = (*mcchieta)[ichii];
        float cphi = (*mcchiphi)[ichii];

        TVector3 chiv;
        chiv.SetPtEtaPhi(cpt,ceta,cphi);
        float drr = chiv.DeltaR(jv);

	if(drr < 0.8 ) matchi = true;
      }




      float haspixel =  0; 
      float sieie = 100;
      float hoe = 100;; 
      float peta = 0; 
      float subjf = -1; 
      int haspho = 0; 
      float jmpr = (*ak8prMassC)[ij];





      bool sh = false;
      if( phoind >= 0 ){
        for(int ipI = 0; ipI < (phoI).size(); ipI++){
          if(phoind == (phoI)[ipI]) sh = true;
	}

        phoI.push_back(phoind);
      }


      

      if(!matchi)h_t31->Fill(t3t1);
      if(matchi) h_t31_m->Fill(t3t1);

      if(phoind >= 0 ){ 
	haspho = 1; 
	haspixel = (*phohaspixelseed)[phoind]; 
	sieie = (*phosieie)[phoind];
	hoe = (*phohoe)[phoind];
	peta = (*phoeta)[phoind];
	subjf = (*ak8subjC)[ij];
	float ppt = (*phopt)[phoind];

        float sp1 = (*ak8spt1)[ij];
        float sp2 = (*ak8spt2)[ij];
        float sp3 = (*ak8spt3)[ij];
        if(!matchi){
          h_spt1->Fill(sp1);
          h_spt2->Fill(sp2);
          h_spt3->Fill(sp3);
          h_phopt->Fill(ppt);
          h_subjf->Fill(subjf);
          h_phohoe->Fill(hoe);
          h_phohaspix->Fill(haspixel);
          if(fabs(peta) < 1.4789 ) h_phosieieB->Fill(sieie);
          if(fabs(peta) > 1.4789 ) h_phosieieE->Fill(sieie);
        }
        if(matchi){
          h_spt1_m->Fill(sp1);
          h_spt2_m->Fill(sp2);
          h_spt3_m->Fill(sp3);
          h_phopt_m->Fill(ppt);
          h_subjf_m->Fill(subjf);
          h_phohoe_m->Fill(hoe);
          h_phohaspix_m->Fill(haspixel);
          if(fabs(peta) < 1.4789 ) h_phosieieB_m->Fill(sieie);
          if(fabs(peta) > 1.4789 ) h_phosieieE_m->Fill(sieie);
        }
      }
      if(!matchi) h_haspho->Fill(haspho);
      if(matchi)  h_haspho_m->Fill(haspho);



      int isL  =   is_Loose( haspho,t3t1,haspixel,peta,sieie,hoe);
      int isT  =   is_Tight( haspho,t3t1,haspixel,subjf,peta,sieie,hoe);
      if(isL && sh == 0) il++;
      if(isT && sh == 0) it++;

      if(isL && sh == 0 ) LM->Fill(jmpr);
      if(isT && sh == 0 ) TM->Fill(jmpr);
     

      
      isLoose.push_back(isL && !sh); 
      isTight.push_back(isT && !sh); 
      ak8pt.push_back(jetpt); 
      ak8phi.push_back(jetphi); 
      ak8eta.push_back(jeteta); 
      ak8m.push_back(jmpr); 
      phoindx.push_back(phoind);

    }
    
    ev->Fill();

    NJLT->Fill(it,il);
       
    if(it == 0 && il == 2) LT20ht->Fill(HTak4);
    if(it == 1 && il == 2) LT21ht->Fill(HTak4);
    if(it == 2 && il == 2) LT22ht->Fill(HTak4);      
    if(it == 0 && il == 1) LT10ht->Fill(HTak4);
    if(it == 1 && il == 1) LT11ht->Fill(HTak4);
    if(it == 0 && il == 0) LT00ht->Fill(HTak4); 

    float mav00 = 0;
    float mav20 = 0;
    float mav21 = 0;
    float mav22 = 0;

    float m1_L2 = 0; 
    float m2_L2 = 0; 

    int e_mav00 = 0;
    int e_mav20 = 0;
    int e_mav21 = 0;
    int e_mav22 = 0;

    phoI.clear();

    for(int ij = 0; ij < (*ak8ptC).size(); ij++){
      float jetpt  = (*ak8ptC)[ij];
      float jeteta = (*ak8etaC)[ij];
      float jetphi = (*ak8etaC)[ij];
      float jmpr = (*ak8prMassC)[ij];
      int   phoind =int( (*ak8phoindxC)[ij]);
      float t3t1  = (*ak8t3t1C)[ij];
      float haspixel =  0; 
      float sieie = 100;
      float hoe = 100;; 
      float peta = 0; 
      float subjf = -1; 
      int   haspho = 0; 
      bool sh = 0;
      
      if( phoind >= 0 ){
	for(int ipI = 0; ipI < (phoI).size(); ipI++){
          if(phoind == (phoI)[ipI]) sh = true;
        }
        phoI.push_back(phoind);
      }

      if(phoind >= 0 ){ 
	haspho = 1; 
	haspixel = (*phohaspixelseed)[phoind]; 
	sieie = (*phosieie)[phoind];
	hoe = (*phohoe)[phoind];
	peta = (*phoeta)[phoind];
	subjf = (*ak8subjC)[ij];
      }
      int isL  =   is_Loose( haspho,t3t1,haspixel,peta,sieie,hoe);
      int isT  =   is_Tight( haspho,t3t1,haspixel,subjf,peta,sieie,hoe);

      isL = isL && !sh; 
      isT = isT && !sh; 


      if(il == 2 ){
	if(isL && m1_L2 ==  0) m1_L2 = jmpr;  
	if(isL && m1_L2 >   0) m2_L2 = jmpr;  
      }
      
      if(it == 0 && il == 0 ) L0->Fill(jetpt);
      if(it == 0 && il == 0){
	LT00M->Fill(jmpr);
      }
      if(it == 0 && il == 1 && isL){
	LT10M->Fill(jmpr);
      }
      if(it == 1 && il == 1 && isT){
	LT11M->Fill(jmpr);
      }
      if(it == 0 && il == 2 && isL){
	LT20M->Fill(jmpr);
	e_mav20++;
	mav20 += jmpr;

      }
      if(it == 1 && il == 2 && isT){
	LT21MT->Fill(jmpr);
      }
      if(it == 1 && il == 2 && isL){
	LT21M->Fill(jmpr);
	e_mav21++;
        mav21 += jmpr;

      }
      if(it == 2 && il == 2 && isT){
	LT22M->Fill(jmpr);
	e_mav22++;
        mav22 += jmpr;


      }

      if(il == 2 && isL ) L2M->Fill(jmpr);
      if(il == 1 && isL) L1->Fill(jetpt);
      if(il == 1 && it == 0  && isL) L11->Fill(jetpt);
      if(il == 1 && it == 1 && isT)T1->Fill(jetpt);
    }
    
    if(il == 2 && m1_L2 > 0 && m2_L2 > 0){
      float m_as = fabs(m1_L2 - m2_L2)/(m1_L2 + m2_L2);
      mas22->Fill(m_as);
    }

    if(il == 2 && it == 2 ){
      if(m1_L2 > m2_L2 ) LT22m_ht->Fill(HTak4,m1_L2);
      if(m2_L2 > m1_L2 ) LT22m_ht->Fill(HTak4,m2_L2);
    }


    if(il == 2 && it == 1 ){
      if(m1_L2 > m2_L2 ) LT21m_ht->Fill(HTak4,m1_L2);
      if(m2_L2 > m1_L2 ) LT21m_ht->Fill(HTak4,m2_L2);
    }


    if(il == 2 && it == 0 ){
      if(m1_L2 > m2_L2 ) LT20m_ht->Fill(HTak4,m1_L2);
      if(m2_L2 > m1_L2 ) LT20m_ht->Fill(HTak4,m2_L2);
    }


    
    if( il ==2 && it == 2) LT22M_2d->Fill(m1_L2,m2_L2); 
    if( il ==2 && it == 0) LT20M_2d->Fill(m1_L2,m2_L2); 
    if( il ==2 && it == 1) LT21M_2d->Fill(m1_L2,m2_L2); 

    if(e_mav22 > 0 && il == 2 && it == 2 ) LT22Mav->Fill(mav22/(1.0*e_mav22));
    if(e_mav20 > 0 && il == 2 && it == 0 ) LT20Mav->Fill(mav20/(1.0*e_mav20));
    if(e_mav21 > 0 && il == 2 && it == 1 ) LT21Mav->Fill(mav21/(1.0*e_mav21));

  
  
  }

  //Scale Histograms to Luminosity;

  float  lumi = 30.0; 
  int totalev = NJ_all->GetEntries();
  float scale = xss*lumi*1000.0/totalev;
  
  TH2F *NJLT_sc   = NJLT->Clone();
  
  TH1F *LM_sc  = LM->Clone();
  TH1F *TM_sc  = TM->Clone();
  TH1F *L2M_sc = L2M->Clone();  
  TH1F *LT00M_sc  = LT00M->Clone(); 
  TH1F *LT10M_sc  = LT10M->Clone();
  TH1F *LT11M_sc  = LT11M->Clone();
  TH1F *LT20M_sc  = LT20M->Clone();
  TH1F *LT21M_sc  = LT21M->Clone();
  TH1F *LT21MT_sc = LT21MT->Clone();
  TH1F *LT22M_sc  = LT22M->Clone();
  TH1F *LT20ht_sc = LT20ht->Clone(); 
  TH1F *LT21ht_sc = LT21ht->Clone();
  TH1F *LT22ht_sc = LT22ht->Clone();
  TH1F *LT10ht_sc = LT10ht->Clone();
  TH1F *LT11ht_sc = LT11ht->Clone();
  TH1F *LT00ht_sc = LT00ht->Clone();

  TH1F *LT20Mav_sc  = LT20Mav->Clone(); 
  TH1F *LT21Mav_sc  = LT21Mav->Clone(); 
  TH1F *LT22Mav_sc  = LT22Mav->Clone();

  
  NJLT_sc->SetName("NJLT_sc");
  LM_sc->SetName("LM_sc");
  TM_sc->SetName("TM_sc");
  L2M_sc->SetName("L2M_sc");
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




  NJLT_sc->Scale(scale);
  LM_sc->Scale(scale);
  TM_sc->Scale(scale);
  L2M_sc->Scale(scale);
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



//  TR->Divide(T1,L1,1.,1.,"B");
//  LR->Divide(L1,L0,1.,1.,"B");
//  TCanvas *c1 = new TCanvas("c1","",1200,600);
//  c1->cd(1); 
//  NJLT->Draw("text"); 
//  c1->SaveAs("res.png");


  TCanvas *c2 = new TCanvas("c2","",700,700);
  c2->cd();
  NJLT_sc->Draw("text");
  NJLT_sc->GetXaxis()->SetTitle("N Tight Jets");
  NJLT_sc->GetYaxis()->SetTitle("N Loose Jets");

  c2->SaveAs(outFp);
  c2->Close();


  
  TFile *f1 = new TFile(outF,"RECREATE");
  f1->cd();

  NJLT->Write();
  NJ_all->Write();

  L0->Write();
  L1->Write();
  T1->Write();

  TR->Write();
  LR->Write();

  LM->Write();
  TM->Write();
  L2M->Write();

  ChiS->Write();


  LT20ht->Write();
  LT21ht->Write();
  LT22ht->Write();

  LT10ht->Write();
  LT11ht->Write();
  LT00ht->Write(); 

  
  LT00M->Write();
  LT10M->Write();
  LT11M->Write();
  LT20M->Write();
  LT21M->Write();
  LT21MT->Write();
  LT22M->Write();

  LT00Mav->Write();
  LT20Mav->Write();
  LT21Mav->Write();
  LT22Mav->Write();
 
  LT22m_ht->Write();
  LT21m_ht->Write();
  LT20m_ht->Write();

  LT20M_2d->Write();
  LT21M_2d->Write();
  LT22M_2d->Write();
  mas22->Write();
  
  NJLT_sc->Write();
  LM_sc->Write();
  TM_sc->Write();
  L2M_sc->Write();
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
    
  h_t31->Write();                                                            
  h_haspho->Write();                                                         
  h_subjf->Write();                                                          
  h_subjfO->Write();
  h_phosieieB->Write();                                                      
  h_phosieieE->Write();                                                      
  h_phohoe->Write();                                                         
  h_phohaspix->Write();                                                      
  h_phopt->Write();

  h_spt1->Write();
  h_spt2->Write();
  h_spt3->Write();

  h_phopt_m->Write();
  h_t31_m->Write();
  h_haspho_m->Write();
  h_subjf_m->Write();
  h_subjfO_m->Write();
  h_phosieieB_m->Write();
  h_phosieieE_m->Write();
  h_phohoe_m->Write();
  h_phohaspix_m->Write();
  h_spt1_m->Write();
  h_spt2_m->Write();
  h_spt3_m->Write();

  
  f1->Close();
  cout<<"Done this point"<<endl;

   
}

             
*/

