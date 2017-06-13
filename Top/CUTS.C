#include <TH1F.h>
#include <TMath.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <TVector3.h>
#include <TTree.h>




void CUTS() {
  int ibatch = 0; // ){ 

  //, int ikind, int mchi, int mglu, float xsec){

  string fin=""; 
  fin ="/cms/kyriacou/Esben/singlemurunFtree.root";
  const char *finc = fin.c_str();
  TFile *f12 = new TFile(finc);
  f12->cd(); 
  demo->cd();
 

  TH1F *hmupt   = new TH1F("hmupt","",100,0,1000);
  TH1F *hak4pt  = new TH1F("hak4pt","",100,0,1000);
  TH1F *hak4eta = new TH1F("hak4eta","",10,-5,5);
  TH1F *hak4phi = new TH1F("hak4phi","",100,-3,3);
  TH1F *hak4e   = new TH1F("hak4e","",100,0,1000);

  TH1F *hmueta  = new TH1F("hmueta","",100,-5,5);
  TH1F *hmuphi  = new TH1F("hmuphi","",100,-3,3);
  TH1F *hmue    = new TH1F("hmue","",100,0,1000);
  
  TH1F *hak8m      = new TH1F("hak8m","",300,0,3000);
  TH1F *hak4m      = new TH1F("hak4m","",300,0,3000);
  TH1F *hak4mum    = new TH1F("hak4mum","",300,0,3000);
  
   

  int NJ; 
  float HTak4; 

  
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
 
  vector<float> *ak4ptC; 
  vector<float> *ak4etaC; 
  vector<float> *ak4phiC; 
  vector<float> *ak4eneC; 
  vector<float> *ak4CSVv2C; 


  vector<float> *muoneta; 
  vector<float> *muonpt; 
  vector<float> *muonphi; 
  vector<float> *muone; 
  vector<float> *muoniso04; 
  vector<float> *muonisGlobal; 
  vector<float> *muonisPF; 

  //photon quantites

  vector<float> *phopt; 
  vector<float> *phoeta; 
  vector<float> *phophi; 
  vector<float> *phohoe; 
  vector<float> *phosieie; 
  vector<float>   *phohaspixelseed; 


  //mc quantities //only relevant for signal sample
 
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



  event->SetBranchAddress("muonpt",&muonpt); 
  event->SetBranchAddress("muoneta",&muoneta); 
  event->SetBranchAddress("muonphi",&muonphi); 
  event->SetBranchAddress("muone",&muone); 
  event->SetBranchAddress("muoniso04",&muoniso04); 
  event->SetBranchAddress("muonisPF",&muonisPF); 
  event->SetBranchAddress("muonisglobal",&muonisGlobal); 


  event->SetBranchAddress("ak4ptC",&ak4ptC); 
  event->SetBranchAddress("ak4etaC",&ak4etaC); 
  event->SetBranchAddress("ak4phiC",&ak4phiC); 
  event->SetBranchAddress("ak4eneC",&ak4eneC); 
  event->SetBranchAddress("ak4CSVv2C",&ak4CSVv2C);  
  



  //int initial = ibatch*1000000; 
  //int final   = (1 + ibatch)*1000000;
  int entt = event->GetEntries();
  //if(final > entt ) final = entt;

  for(int i  = 0; i < 9000000;i++){
    //  for(int i  = initial; i < final;   i++){
    event->GetEntry(i);

    if( i % 100000 == 0 ) cout<<i<<" "<<9000000<<endl;



    bool pass = true; 
    
    for(int ijet = 0 ; ijet < (*ak8ptC).size(); ijet++){
      float jpt  = (*ak8ptC)[ijet]; 
      float jeta = (*ak8etaC)[ijet]; 
      float jphi = (*ak8phiC)[ijet]; 
      float jmpr= (*ak8prMassC)[ijet];      
      hak8m->Fill(jmpr);
    }


    for(int ijet = 0 ; ijet < (*ak4ptC).size(); ijet++){
      float jpt  = (*ak4ptC)[ijet]; 
      float jeta = (*ak4etaC)[ijet]; 
      float jphi = (*ak4phiC)[ijet]; 
      float jene = (*ak4eneC)[ijet]; 
      float csv2 = (*ak4CSVv2C)[ijet]; 

      //      float jmpr= (*ak4prMassC)[ij];      
    
      if(csv2 < 0.84) continue; 

      TLorentzVector j4; 
      j4.SetPtEtaPhiE(jpt,jeta,jphi,jene);
      float j4m = j4.Mag();
      hak4m->Fill(j4m);
      hak4pt->Fill(jpt);
      hak4eta->Fill(jeta);
      hak4phi->Fill(jphi);
      hak4e->Fill(jene); 

      for(int im = 0 ; im < (*muonpt).size(); im ++){
       
	float mpt  = (*muonpt)[im]; 
	float meta = (*muoneta)[im]; 
	float mphi = (*muonphi)[im]; 
	float mene = (*muone)[im]; 
	float isg  = (*muonisGlobal)[im]; 
	float ispf = (*muonisPF)[im]; 
	
	
	
	TLorentzVector m4; 
	m4.SetPtEtaPhiE(mpt,meta,mphi,mene);
	m4 = m4 + j4m; 
	float mj4mu = m4.Mag();
	hak4mum->Fill(mj4mu);
      }
      

    }

    for(int im = 0 ; im < (*muonpt).size(); im ++){
      float mpt = (*muonpt)[im]; 
      float meta = (*muoneta)[im]; 
      float mphi = (*muonphi)[im]; 
      float mene = (*muone)[im]; 

      
      hmueta->Fill(meta);
      hmuphi->Fill(mphi);
      hmue->Fill(mene);
      hmupt->Fill(mpt);
    }

   
  } //EOF event



  TFile *f2 = new TFile("tops.root","recreate");

  hmupt->Write();
  hak4pt->Write();
  hak4eta->Write();
  hak4phi->Write();
  hak4e->Write();

  hmueta->Write();
  hmuphi->Write();
  hmue->Write();
  
  hak8m->Write();
  hak4m->Write();
  hak4mum->Write();
  

}

             
