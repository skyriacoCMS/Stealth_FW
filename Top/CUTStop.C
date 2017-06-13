#include <TH1F.h>
#include <TMath.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <TVector3.h>
#include <TTree.h>




void CUTStop(int ibatch, int irun){ 

  //, int ikind, int mchi, int mglu, float xsec){

  string fin=""; 
  if(irun == 0 ) fin ="/cms/kyriacou/Esben/singlemurunBtree.root";
  if(irun == 1 ) fin ="/cms/kyriacou/Esben/singlemurunDtree.root";
  if(irun == 2 ) fin ="/cms/kyriacou/Esben/singlemurunEtree.root";
  if(irun == 3 ) fin ="/cms/kyriacou/Esben/singlemurunFtree.root";
  if(irun == 4 ) fin ="/cms/kyriacou/Esben/datamuonrunG.root";
 
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
  
  TH1F *hak8m      = new TH1F("hak8m","",1000,0,1000);
  TH1F *hak4m      = new TH1F("hak4m","",1000,0,1000);
  TH1F *hak4mum    = new TH1F("hak4mum","",1000,0,1000);

  TH1F *hak4mumak8  = new TH1F("hak4mumak8","",1000,0,1000);

  TH1F *hmuispf     = new TH1F("hmuispf","",200,0,2);
  TH1F *hmuiso      = new TH1F("hmuiso","",100,0,1);
  TH1F *hmuisglobal = new TH1F("hmuisglobal","",200,0,2);

  TH1F *h3jetmass  = new TH1F("h3jetmass","",1000,0,1000);

  
   

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
  



  int initial = ibatch*1000000; 
  int final   = (1 + ibatch)*1000000;
  int entt = event->GetEntries();
  if(final > entt ) final = entt;

  for(int i  = initial; i < final; i++){
    //  for(int i  = initial; i < final;   i++){
    event->GetEntry(i);

    //  if( i % 100000 == 0 ) cout<<i<<" "<<9000000<<endl;
    int btags = 0; 
    int iak4 = 0; 
    for(int ijet = 0 ; ijet < (*ak4ptC).size(); ijet++){
	float jpt  = (*ak4ptC)[ijet]; 
	float jeta = (*ak4etaC)[ijet]; 
	float jphi = (*ak4phiC)[ijet]; 
	float jene = (*ak4eneC)[ijet]; 
	float csv2 = (*ak4CSVv2C)[ijet]; 
	if(fabs(jeta) > 2.4 ) continue; 
	if(jpt < 50 ) continue; 
	//      float jmpr= (*ak4prMassC)[ij];      
	iak4++; 

	if(csv2 < 0.5426 ) continue; 
	btags ++;
    }

    if(btags != 2 || iak4 != 4 ) continue; 
    int nmus = 0; 
    float selmphi = -1; 

    for(int im = 0 ; im < (*muonpt).size(); im ++){
      float mpt  = (*muonpt)[im]; 
      float meta = (*muoneta)[im]; 
      float mphi = (*muonphi)[im]; 
      float mene = (*muone)[im]; 
      float isg  = (*muonisGlobal)[im]; 
      float ispf = (*muonisPF)[im]; 
      float muoniso = (*muoniso04)[im];
      if(muoniso > 0.25 ) continue; 
      if(ispf && isg && mpt > 55 ) nmus ++;
      selmphi = mphi; 
    }

    if( nmus ! = 1 ) continue; 

    bool pass = true; 
    
    for(int ijet = 0 ; ijet < (*ak8ptC).size(); ijet++){
      float jpt  = (*ak8ptC)[ijet]; 
      float jeta = (*ak8etaC)[ijet]; 
      float jphi = (*ak8phiC)[ijet]; 
      float jmpr= (*ak8prMassC)[ijet];      

      //if(jpt < 170 ) continue; 
      TLorentzVector j8; 
      j8.SetPtEtaPhiM(jpt,jeta,jphi,jmpr);
      
      if( (jphi - selmphi)  <  2*(TMath::Pi())/3.0 ) continue; 

      int hasb = 0; 

      for(int ijet = 0 ; ijet < (*ak4ptC).size(); ijet++){
	float csv2 = (*ak4CSVv2C)[ijet]; 
	
	if(csv2 < 0.5426) continue; 
	//	if(csv2 < 0.8484) continue; 
	
	float jpt  = (*ak4ptC)[ijet]; 
	float jeta = (*ak4etaC)[ijet]; 
	float jphi = (*ak4phiC)[ijet]; 
	float jene = (*ak4eneC)[ijet]; 
	TLorentzVector j4; 
	j4.SetPtEtaPhiE(jpt,jeta,jphi,jene);
	float drr = j4.DeltaR(j8);
	if(drr < 0.8 ) hasb++; 
      }
      if(hasb > 0 ) hak8m->Fill(jmpr);
    }

    int ib1 = -1; 
    int ib2 = -1; 

    TLorentzVector j1,j2,j3,j4, jb1, jb2;
    
    for(int ijet = 0 ; ijet < (*ak4ptC).size(); ijet++){
      float jpt  = (*ak4ptC)[ijet]; 
      float jeta = (*ak4etaC)[ijet]; 
      float jphi = (*ak4phiC)[ijet]; 
      float jene = (*ak4eneC)[ijet]; 
      float csv2 = (*ak4CSVv2C)[ijet]; 
      
      if(jpt < 50 ) continue; 
      if(fabs(jeta ) > 2.4 ) continue;
     
      if(csv2 > 0.5426){      
	
	if(ib1 == -1){
	  ib1 = ijet;
	  jb1.SetPtEtaPhiE(jpt,jeta,jphi,jene);
	}
	if(ib1 != -1){
	  ib2 = ijet;
	  jb2.SetPtEtaPhiE(jpt,jeta,jphi,jene);
	}
      }

      
      if(ijet == 0 )  j1.SetPtEtaPhiE(jpt,jeta,jphi,jene);
      if(ijet == 1 )  j2.SetPtEtaPhiE(jpt,jeta,jphi,jene);
      if(ijet == 2 )  j3.SetPtEtaPhiE(jpt,jeta,jphi,jene);
      if(ijet == 3 )  j4.SetPtEtaPhiE(jpt,jeta,jphi,jene);
    }
   
    TLorentzVector com1,com2;

    cout<<ib1<<" "<<ib2<<endl;
 
    if(ib1 == 0 && ib2 == 1){ 
      com1 = jb1 + j3+j4; 
      com2 = jb2 + j3+j4; 
    }


    if(ib1 == 0 && ib2 == 2){ 
      com1 = jb1 + j2+j4; 
      com2 = jb2 + j2+j4; 
    }


    if(ib1 == 0 && ib2 == 3){ 
      com1 = jb1 + j2+j3; 
      com2 = jb2 + j2+j3; 
    }


    if(ib1 == 1 && ib2 == 2){ 
      com1 = jb1 + j1+j4; 
      com2 = jb2 + j1+j4; 
    }

    if(ib1 == 1 && ib2 == 3){ 
      com1 = jb1 + j1+j3; 
      com2 = jb2 + j1+j3; 
    }


    if(ib1 == 2 && ib2 == 3){ 
      com1 = jb1 + j1+j2; 
      com2 = jb2 + j1+j2; 
    }


    if(ib1 != -1 && ib2 != -1){
      h3jetmass->Fill(com1.Mag());
      h3jetmass->Fill(com2.Mag());
    }




    for(int im = 0 ; im < (*muonpt).size(); im ++){
      float mpt  = (*muonpt)[im]; 
      float meta = (*muoneta)[im]; 
      float mphi = (*muonphi)[im]; 
      float mene = (*muone)[im]; 
      float isg  = (*muonisGlobal)[im]; 
      float ispf = (*muonisPF)[im]; 
      float muoniso = (*muoniso04)[im];
      if(muoniso > 0.25 ) continue; 
      if(fabs(meta) > 2.4 ) continue; 
      if(fabs(mpt) < 55 ) continue; 
      if(!ispf && !isg) continue;
      TLorentzVector m4; 
      m4.SetPtEtaPhiE(mpt,meta,mphi,mene);
      float mj4mu = 0; 
      float drmin = 99; 
      
      for(int ijet = 0 ; ijet < (*ak4ptC).size(); ijet++){
	float jpt  = (*ak4ptC)[ijet]; 
	float jeta = (*ak4etaC)[ijet]; 
	float jphi = (*ak4phiC)[ijet]; 
	float jene = (*ak4eneC)[ijet]; 
	float csv2 = (*ak4CSVv2C)[ijet]; 
	if(csv2 < 0.84) continue; 
	TLorentzVector j4; 
	j4.SetPtEtaPhiE(jpt,jeta,jphi,jene);
	float j4m = j4.Mag();
	hak4m->Fill(j4m);
	hak4pt->Fill(jpt);
	hak4eta->Fill(jeta);
	hak4phi->Fill(jphi);
	hak4e->Fill(jene);
	float drr = m4.DeltaR(j4);
	m4 = m4 + j4m; 
	if( drr < drmin )  mj4mu =m4.Mag();
      }
      hak4mum->Fill(mj4mu); 
    }
    
    
    for(int im = 0 ; im < (*muonpt).size(); im ++){
      float mpt = (*muonpt)[im]; 
      float meta = (*muoneta)[im]; 
      float mphi = (*muonphi)[im]; 
      float mene = (*muone)[im]; 
      float isg  = (*muonisGlobal)[im]; 
      float ispf = (*muonisPF)[im]; 
      float muoniso = (*muoniso04)[im];
      
      hmueta->Fill(meta);
      hmuphi->Fill(mphi);
      hmue->Fill(mene);
      hmupt->Fill(mpt);
      
      hmuispf->Fill(ispf);
      hmuiso->Fill(muoniso);
      hmuisglobal->Fill(isg);
      
      
      
    }
    
    
  } //EOF event
  
  ostringstream btc;
  btc << ibatch;
  string fout; 
  
  if(irun == 0) fout ="./PlotsB/tops"+btc.str()+"2bs.root";
  if(irun == 1) fout ="./PlotsD/tops"+btc.str()+"2bs.root";
  if(irun == 2) fout ="./PlotsE/tops"+btc.str()+"2bs.root";
  if(irun == 3) fout ="./PlotsF/tops"+btc.str()+"2bs.root";
  if(irun == 4) fout ="./PlotsG/tops"+btc.str()+"2bs.root";
  const char *foutc = fout.c_str();


  TFile *f2 = new TFile(foutc,"recreate");

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

  hmuispf->Write();
  hmuiso->Write();
  hmuisglobal->Write();
  hak4mumak8->Write();    
  h3jetmass->Write();
}

             
