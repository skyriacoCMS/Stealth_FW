#include <TH1F.h>
#include <TMath.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <TVector3.h>
#include <TTree.h>




void CUTS4(int ibatch, int ikind, int mchi, int mglu, float xsec){

  string fin=""; 
  if(ikind == 0 ) fin ="../../../../../Trees/treerunG.root";
  if(ikind == 1 ) fin ="../../../../../Trees/q115all.root";
  if(ikind == 2 ) fin ="../../../../../Trees/q152all.root";
  if(ikind == 3 ) fin ="../../../../../Trees/q2inf_all.root";
  if(ikind == 4 ) fin ="../../../../Trees/sig.root";


  const char *finc = fin.c_str();
  TFile *f12 = new TFile(finc);
  f12->cd(); 
  demo->cd();

  TH2D *NJLT    = new TH2D("NJLT","",5,0,5,5,0,5);
  TH1F * mas22 = new TH1F("mas22","",100,0,2);

  TH1F *NJ_all  = new TH1F("NJ_all","",100,0,100);

  TH1F *L0     = new TH1F("L0","",45,200,2000); //,10,-5,5);                    
  TH1F *L1     = new TH1F("L1","",45,200,2000); //,10,-5,5);                    
  TH1F *L11    = new TH1F("L11","",45,200,2000); //,10,-5,5);                    
  TH1F *T1     = new TH1F("T1","",45,200,2000); //,10,-5,5);                    

  TH1F *TR     = new TH1F("TR","",45,200,2000); //,10,-5,5);                    
  TH1F *LR     = new TH1F("LR","",45,200,2000); //,10,-5,5);              

  TH1F *drL0   = new TH1F("drL0","",60,0,6); //,10,-5,5);              
  TH1F *drL1   = new TH1F("drL1","",60,0,6); //,10,-5,5);              
  TH1F *drT1   = new TH1F("drT1","",60,0,6); //,10,-5,5);              




  TH1F *TReta     = new TH1F("TReta","",20,-5,5);                    
  TH1F *LReta     = new TH1F("LReta","",20,-5,5);              
  TH1F *T1eta     = new TH1F("T1eta","",20,-5,5);                    
  TH1F *L1eta     = new TH1F("L1eta","",20,-5,5);              
  TH1F *L0eta     = new TH1F("L0eta","",20,-5,5);                    





                                                                                 
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

                                                                                  
  TH1F *LT20ht     = new TH1F("LT20ht","",30,1000,4000);                         
  TH1F *LT21ht     = new TH1F("LT21ht","",30,1000,4000);                         
  TH1F *LT22ht     = new TH1F("LT22ht","",30,1000,4000);                         
                                                                                  
  TH1F *LT10ht     = new TH1F("LT10ht","",30,1000,4000);                         
  TH1F *LT11ht     = new TH1F("LT11ht","",30,1000,4000);                         
  TH1F *LT00ht     = new TH1F("LT00ht","",30,1000,4000);       

  TH2F *LT22m_ht   = new TH2F("LT22m_ht","",30,1000,4000,50,0,1000);
  TH2F *LT21m_ht   = new TH2F("LT21m_ht","",30,1000,4000,50,0,1000);
  TH2F *LT20m_ht   = new TH2F("LT20m_ht","",30,1000,4000,50,0,1000);
  


  TH1F *h_phopt       = new TH1F("h_phopt","",100,0,1000);
  TH1F *h_t31         = new TH1F("h_t31","",100,0,1);                           
  TH1F *h_haspho      = new TH1F("h_haspho","",18,-1,2);                         
  TH1F *h_subjf       = new TH1F("h_subjf","",100,0,1);                         
  TH1F *h_phosieieB   = new TH1F("h_phosieieB","",80,0.004,0.012);             
  TH1F *h_phosieieE   = new TH1F("h_phosieieE","",40,0.02,0.03);              
  TH1F *h_phohoe      = new TH1F("h_phohoe","",100,0,0.15);                  
  TH1F *h_phohaspix   = new TH1F("h_phohaspix","",100,-1,2);                  
  TH1F *h_spt1        = new TH1F("h_spt1","",100,0,1000);
  TH1F *h_spt2        = new TH1F("h_spt2","",100,0,1000);
  TH1F *h_spt3        = new TH1F("h_spt3","",100,0,1000);
 
  TH1F *h_phopt_m     = new TH1F("h_phopt_m","",100,0,1000);
  TH1F *h_t31_m       = new TH1F("h_t31_m","",100,0,1);
  TH1F *h_haspho_m    = new TH1F("h_haspho_m","",18,-1,2);
  TH1F *h_subjf_m     = new TH1F("h_subjf_m","",100,-1,2);
  TH1F *h_phosieieB_m = new TH1F("h_phosieieB_m","",80,0.004,0.012);
  TH1F *h_phosieieE_m = new TH1F("h_phosieieE_m","",40,0.02,0.03);
  TH1F *h_phohoe_m    = new TH1F("h_phohoe_m","",100,0,0.15);
  TH1F *h_phohaspix_m = new TH1F("h_phohaspix_m","",100,-1,2);
  TH1F *h_spt1_m      = new TH1F("h_spt1_m","",100,0,1000);
  TH1F *h_spt2_m      = new TH1F("h_spt2_m","",100,0,1000);
  TH1F *h_spt3_m      = new TH1F("h_spt3_m","",100,0,1000);





  h_t31->Sumw2();                                                            
  h_haspho->Sumw2();                                                         
  h_subjf->Sumw2();                                                          
  h_phopt->Sumw2();
  h_phosieieB->Sumw2();                                                      
  h_phosieieE->Sumw2();                                                      
  h_phohoe->Sumw2();                                                         
  h_phohaspix->Sumw2();                                                      
  h_spt1->Sumw2();
  h_spt2->Sumw2();
  h_spt3->Sumw2();

  h_t31_m->Sumw2();                                                            
  h_haspho_m->Sumw2();                                                         
  h_subjf_m->Sumw2();                                                          
  h_phopt_m->Sumw2();
  h_phosieieB_m->Sumw2();                                                      
  h_phosieieE_m->Sumw2();                                                      
  h_phohoe_m->Sumw2();                                                         
  h_phohaspix_m->Sumw2();                                                      
  h_spt1_m->Sumw2();
  h_spt2_m->Sumw2();
  h_spt3_m->Sumw2();


  
  TReta->Sumw2();
  LReta->Sumw2();
  T1eta->Sumw2();
  L1eta->Sumw2();
  L0eta->Sumw2();

  drL0->Sumw2();
  drL1->Sumw2();
  drT1->Sumw2();


  
  //Setting output
  ostringstream btc; 
  btc << ibatch; 
  string  fout  = "./Plots/Plots_ptcutnj4_"+btc.str()+".root";
  string  fcut  = "./CutPlots/cuts_ptcutnj4_"+btc.str()+".root";
  string  ftree = "./JetTrees/jetTree_ptcutnj4_"+btc.str()+".root";
  if(ikind == 4){
    ostringstream mch;
    ostringstream mgl;
    mch<<mchi;
    mgl<<mglu;
    fout = "./FewMassP/chi_"+mch.str()+"glu_"+mgl.str()+"_"+btc.str()+"nj4.root";
    fcut = "./FewMassP/cuts_chi_"+mch.str()+"glu_"+mgl.str()+"_"+btc.str()+"nj4.root";
    ftree = "./FewMassP/jetTree_nj3drsel_"+mch.str()+"glu_"+mgl.str()+"_"+btc.str()+"nj4.root";
  }
  const char *foutc = fout.c_str();
  const char *fcutc = fcut.c_str();
  const char *ftreec = ftree.c_str();

  TFile *f2 = new TFile(ftreec,"recreate");
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
  vector<float> *ak8spt1; 
  vector<float> *ak8spt2; 
  vector<float> *ak8spt3; 
 
  //photon quantites

  vector<float> *phopt; 
  vector<float> *phoeta; 
  vector<float> *phophi; 
  vector<float> *phohoe; 
  vector<float> *phosieie; 
  vector<float>   *phohaspixelseed; 


  //mc quantities //only relevant for signal sample
  float mcglumass;
  float mcchimass;
  vector<float> *mcchipt;
  vector<float> *mcchieta;
  vector<float> *mcchiphi;

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

  if(ikind == 4){
    event->SetBranchAddress("mcglumass",&mcglumass);
    event->SetBranchAddress("mcchimass",&mcchimass);
    event->SetBranchAddress("mcchipt",&mcchipt);
    event->SetBranchAddress("mcchieta",&mcchieta);
    event->SetBranchAddress("mcchiphi",&mcchiphi);
  }
  


  int initial = ibatch*100000; 
  int final   = (1 + ibatch)*100000;
  int entt = event->GetEntries();
  if(final > entt ) final = entt;

  
  for(int i  = initial; i < final;   i++){
    event->GetEntry(i);


    if(ikind == 4){
      if(mcglumass < mglu - 20 || mcglumass >  mglu + 20 ) continue;
      if(mcchimass  >= 150){
	if( mcchimass < mchi  - 10  || mcchimass >  mchi + 10 ) continue;
      } else{
	if( mcchimass < mchi  - 5  || mcchimass >  mchi + 5   ) continue;
      }
    }

    NJ_all->Fill(NJ);


    //    if( HTak4 < 1000) continue;  
    if(NJ < 4   || HTak4 < 1000 ) continue; 

    if(i % 1000 == 0 ) cout<<"entry: "<<i <<" "<<entt<<endl;
    htak4 = HTak4; 


    isLoose.clear(); 
    isTight.clear(); 
    ak8pt.clear(); 
    ak8phi.clear(); 
    ak8eta.clear(); 
    ak8m.clear();
    phoindx.clear();

    bool pass = true; 
    
    for(int ijet = 0 ; ijet < (*ak8ptC).size(); ijet++){
      TVector3 jv1; 
      float jpt  = (*ak8ptC)[ijet]; 
      float jeta = (*ak8etaC)[ijet]; 
      float jphi = (*ak8phiC)[ijet]; 
      jv1.SetPtEtaPhi(jpt,jeta,jphi);
      
      for(int ijet2 = 0 ; ijet2 < (*ak8ptC).size(); ijet2++){
	if(ijet2 == ijet ) continue;
	float jpt2  = (*ak8ptC)[ijet2]; 
	float jeta2 = (*ak8etaC)[ijet2]; 
	float jphi2 = (*ak8phiC)[ijet2];
	TVector3 jv2; 
	jv2.SetPtEtaPhi(jpt2,jeta2,jphi2);
	float dr12 = jv1.DeltaR(jv2);
	
	if(dr12 < 1.4 ) pass = false;  
      }
      
    }
    
    if(!pass) continue; 
    int it = 0; 
    int il = 0; 

    vector<int> phoI;
    phoI.clear();
    float mindr = 99; 
    for (int ij = 0; ij < (*ak8ptC).size(); ij++){



      float jetpt  = (*ak8ptC)[ij];
      float jeteta = (*ak8etaC)[ij];
      
      if(jetpt > 1000) continue; 






      float jetphi = (*ak8phiC)[ij];
      int   phoind = int( (*ak8phoindxC)[ij] );
      float t3t1  = (*ak8t3t1C)[ij];
     
      bool sh = false; 
      if( phoind >= 0 ){
	for(int ipI = 0; ipI < (phoI).size(); ipI++){ 
	  if(phoind == (phoI)[ipI]) sh = true; 	
	}
	
	phoI.push_back(phoind);
      }

      bool matchi = false;

      if( ikind == 4 ){
	
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
      }
      
      

     
      int haspixel =  0; 
      float sieie = 100;
      float hoe = 100;; 
      float peta = 0; 
      float subjf = -1; 
      int haspho = 0; 

      
      h_haspho->Fill(haspho);
      h_t31->Fill(t3t1);      
      
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
        if(matchi && ikind == 4){
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
      if(matchi && ikind == 4)  h_haspho_m->Fill(haspho);


      float jmpr= (*ak8prMassC)[ij];      

      int isL  =   is_Loose( haspho,t3t1,haspixel,peta,sieie,hoe);
      int isT  =   is_Tight( haspho,t3t1,haspixel,subjf,peta,sieie,hoe);
      
      // if(isL) cout<<isL<<endl;


      if(isL && sh == 0) il++; 
      if(isT && sh == 0) it++; 
      
      if(isL && sh == 0 ) LM->Fill(jmpr);
      if(isT && sh == 0 ) TM->Fill(jmpr);

      isLoose.push_back(isL &&  !sh); 
      isTight.push_back(isT &&  !sh); 
      ak8pt.push_back(jetpt); 
      ak8phi.push_back(jetphi); 
      ak8eta.push_back(jeteta); 
      ak8m.push_back(jmpr); 
      phoindx.push_back(phoind);
    }

    ev->Fill();
    NJLT->Fill(it,il);
    
                                                                             

    float mav00 = 0; 
    float mav20 = 0; 
    float mav21 = 0; 
    float mav22 = 0; 

    int e_mav00 = 0; 
    int e_mav20 = 0; 
    int e_mav21 = 0; 
    int e_mav22 = 0; 

    float m1_L2 = 0;
    float m2_L2 = 0;



    phoI.clear();
    for(int ij = 0; ij < (*ak8ptC).size(); ij++){
      float jetpt  = (*ak8ptC)[ij];
      float jeteta = (*ak8etaC)[ij];

      if(jetpt > 1000) continue; 

      	float mindr = 99; 
	TVector3 jv1e,jv2e;
	jv1e.SetPtEtaPhi(jetpt,jeteta,jetphi);
	for(int ik = 0; ik < (*ak8ptC).size(); ik++){
	  if( ik == ij ) continue;
	  float pt1  =  (*ak8ptC)[0]; 
	  float phi1 =  (*ak8phiC)[0];
	  float eta1 =  (*ak8etaC)[0];
	  jv2e.SetPtEtaPhi(pt1,eta1,phi1);
	  float dr12 = jv1e.DeltaR(jv2e);
	  if( dr12 < mindr) mindr = dr12;
	}




      float jetphi = (*ak8phiC)[ij];
      if(it == 0 && il == 0 ){

	//cALCULATING dr
	drL0->Fill(mindr);
	L0->Fill(jetpt);	
	L0eta->Fill(jeteta);
      }
      int   phoind =int( (*ak8phoindxC)[ij]);
      float t3t1  = (*ak8t3t1C)[ij];
      
      int haspixel =  0; 
      float sieie = 100;
      float hoe = 100;; 
      float peta = 0; 
      float subjf = -1; 
      int haspho = 0; 
      
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
      
      float jmpr= (*ak8prMassC)[ij];      
      int isL  =   is_Loose( haspho,t3t1,haspixel,peta,sieie,hoe);
      int isT  =   is_Tight( haspho,t3t1,haspixel,subjf,peta,sieie,hoe);
      isL = isL && !sh;
      isT = isT && !sh;

      
      if(il == 2 ){
        if(isL && m1_L2 ==  0) m1_L2 = jmpr;
        if(isL && m1_L2 >   0) m2_L2 = jmpr;
      }

      
      
      if(il == 2 && isL) L2M->Fill(jmpr);

      if(isL && il == 1){
	L1->Fill(jetpt);
	L1eta->Fill(jeteta);
	drL1->Fill(mindr);

      }
     if(il  == 1 ){
	
	if(it == 0  && isL) L11->Fill(jetpt);
	if(it == 1 && isT){
	  T1->Fill(jetpt);
	  T1eta->Fill(jeteta);
	  drT1->Fill(mindr);
	  
	}
     }
         
      if(it == 0 && il == 0){ 
	e_mav00++; 
	mav00 += jmpr; 
	LT00M->Fill(jmpr);                                        
      }                                                           
      if(it == 0 && il == 1 && isL){                              
	LT10M->Fill(jmpr);                                        
      }


     
      if(it == 1 && il == 1 && isT){                              
        LT11M->Fill(jmpr);                                        
      }                                                           
      if(it == 0 && il == 2 && isL){                              
	e_mav20++;
	mav20 += jmpr;
        LT20M->Fill(jmpr);                                        
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

    }

    if( il ==2 ){
      if( m1_L2 > 0 && m2_L2 > 0){
	float m_as = fabs(m1_L2 - m2_L2)/(m1_L2 + m2_L2);
	mas22->Fill(m_as);
      }
    }


    
    if(it == 0 && il == 2){
	 LT20ht->Fill(HTak4);
	 if(e_mav20 > 0 ) LT20Mav->Fill(mav20/(1.0*e_mav20));
	 LT20M_2d->Fill(m1_L2,m2_L2);
	
    }
    
    if(it == 1 && il == 2){
      LT21ht->Fill(HTak4);                                   
      if(e_mav21 > 0 ) LT21Mav->Fill(mav21/(1.0*e_mav21));
      LT21M_2d->Fill(m1_L2,m2_L2);
    }
    
    if(it == 2 && il == 2){
      LT22ht->Fill(HTak4);
      if(e_mav22 > 0 ) LT22Mav->Fill(mav22/(1.0*e_mav22));
      LT22M_2d->Fill(m1_L2,m2_L2);

   }

    if(it == 0 && il == 1) LT10ht->Fill(HTak4);                                   
    if(it == 1 && il == 1) LT11ht->Fill(HTak4);                                   
    if(it == 0 && il == 0) LT00ht->Fill(HTak4);                                

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



   
  } //EOF event


  TR->Divide(T1,L1,1.,1.,"B");
  LR->Divide(L1,L0,1.,1.,"B");
  LReta->Divide(L1eta,L0eta,1.,1.,"B");
  TReta->Divide(T1eta,L1eta,1.,1.,"B");
 
  /*
  TCanvas *c1 = new TCanvas("c1","",1200,600);
  c1->cd(1); 
  NJLT->Draw("text"); 
  c1->SaveAs("res.png");
  */

  //Scaling and saving
  TH2F *NJLT_sc  = NJLT->Clone();                                 
  TH1F *L0_sc    = L0->Clone();
  TH1F *L1_sc    = L1->Clone();
  TH1F *L11_sc   = L11->Clone();
  TH1F *T1_sc    = T1->Clone();
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
  L0_sc->SetName("L0_sc");
  L11_sc->SetName("L11_sc");
  L1_sc->SetName("L1_sc");
  T1_sc->SetName("T1_sc");
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



  


  int ntot = entt; 
  float xsec115  = 1206.0;                                                      
  float xsec152  = 120.4;                                                       
  float xsec2inf = 25.25; 
  
  double scale = 1; 
  if(ikind == 1 ) 1.0*1000.0*xsec115/ntot;
  if(ikind == 2 ) 1.0*1000.0*xsec152/ntot;
  if(ikind == 3 ) 1.0*1000.0*xsec2inf/ntot;
  if(ikind == 4 ) 1.0*1000.0*xsec; 


                                                            
  NJLT_sc->Scale(scale);                                      
                                
  L0_sc->Scale(scale);
  L11_sc->Scale(scale);
  L1_sc->Scale(scale);
  T1_sc->Scale(scale);

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



  
  TFile *f1 = new TFile(foutc,"recreate");
  NJLT->Write();
  NJ_all->Write();
  
  L0->Write();
  L1->Write();
  T1->Write();

  drL0->Write();
  drL1->Write();
  drT1->Write();

  TR->Write();
  LR->Write();

  TReta->Write();
  LReta->Write();
  T1eta->Write();
  L1eta->Write();
  L0eta->Write();

  drL0->Write();
  drL1->Write();
  drT1->Write();



  LT20ht->Write();                                                                
  LT21ht->Write();                                                                
  LT22ht->Write();                                                                
                                                                                  
  LT10ht->Write();                                                                
  LT11ht->Write();                                                                
  LT00ht->Write();     

  LT22m_ht->Write();
  LT21m_ht->Write();
  LT20m_ht->Write();

  LT00M->Write();                                 
  LT10M->Write();                                 
  LT11M->Write();                                 
  LT20M->Write();                                 
  LT21M->Write();                                 
  LT21MT->Write();                                
  LT22M->Write();                
                                                 
  LM->Write();                                    
  TM->Write();                                    
  L2M->Write();   

  LT00Mav->Write();
  LT20Mav->Write();
  LT21Mav->Write();
  LT22Mav->Write();


                                                             
  NJLT_sc->Write();                                           
                                
  L0_sc->Write();
  L11_sc->Write();
  L1_sc->Write();
  T1_sc->Write();

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

  LT20M_2d->Write();
  LT21M_2d->Write();
  LT22M_2d->Write();
  mas22->Write();

  LT20Mav_sc->Write();
  LT21Mav_sc->Write();
  LT22Mav_sc->Write();




  f2->cd();
  ev->Write();

  
  TFile *f23 = new TFile(fcutc,"recreate");                            
  h_t31->Write();                                                            
  h_haspho->Write();                                                         
  h_subjf->Write();                                                          
  h_phopt->Write();
  h_phosieieB->Write();                                                      
  h_phosieieE->Write();                                                      
  h_phohoe->Write();                                                         
  h_phohaspix->Write();                                                      
  h_spt1->Write();
  h_spt2->Write();
  h_spt3->Write();


  if(ikind == 4 ){
    h_phopt_m->Write();
    h_t31_m->Write();
    h_haspho_m->Write();
    h_subjf_m->Write();
    h_phosieieB_m->Write();
    h_phosieieE_m->Write();
    h_phohoe_m->Write();
    h_phohaspix_m->Write();
    h_spt1_m->Write();
    h_spt2_m->Write();
    h_spt3_m->Write();
  }
                              

   
}

             


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
  if(haspixel == 0 && haspho && t3t1 < 0.5 && subjf > 0.9 ){
    //return 1; 
    if(fabs(phoeta) < 1.4789 && phosie < 0.019 && phohoe < 0.05) return 1; 
    if(fabs(phoeta) > 1.4789 && phosie < 0.03 && phohoe < 0.05) return 1; 
  }
  return 0; 
}


