
// Important: The name of the file needs to
// be identical to the name of the function:
void E7_analysis() {

    // Define the name of the input file:
    // * "../output" means go into parent directory and then into 'output'
    // Before telescope alignment:
    std::string fileName_before = "../output/07_telescope_alignment.root";
    std::string fileName_after = "../output/07_tracking_aligned.root";

    // Open the files
    TFile *f1 = TFile::Open(fileName_before.c_str());
    TFile *f2 = TFile::Open(fileName_after.c_str());

    // Set the name of the histogram we want to draw:
    // * make sure that the name matches exactly to the one you see in the TBrowser
    std::string hist_trackChiSqndof = "Tracking4D/trackChi2ndof";
    
    std::string hist_tpx0LocalResidualsX = "Tracking4D/Timepix3_0/local_residuals/LocalResidualsX";
    std::string hist_tpx0LocalResidualsY = "Tracking4D/Timepix3_0/local_residuals/LocalResidualsY";
    std::string hist_tpx1LocalResidualsX = "Tracking4D/Timepix3_1/local_residuals/LocalResidualsX";
    std::string hist_tpx1LocalResidualsY = "Tracking4D/Timepix3_1/local_residuals/LocalResidualsY";
    std::string hist_tpx2LocalResidualsX = "Tracking4D/Timepix3_2/local_residuals/LocalResidualsX";
    std::string hist_tpx2LocalResidualsY = "Tracking4D/Timepix3_2/local_residuals/LocalResidualsY";
    std::string hist_tpx3LocalResidualsX = "Tracking4D/Timepix3_3/local_residuals/LocalResidualsX";
    std::string hist_tpx3LocalResidualsY = "Tracking4D/Timepix3_3/local_residuals/LocalResidualsY";
    std::string hist_tpx4LocalResidualsX = "Tracking4D/Timepix3_4/local_residuals/LocalResidualsX";
    std::string hist_tpx4LocalResidualsY = "Tracking4D/Timepix3_4/local_residuals/LocalResidualsY";
    std::string hist_tpx5LocalResidualsX = "Tracking4D/Timepix3_5/local_residuals/LocalResidualsX";
    std::string hist_tpx5LocalResidualsY = "Tracking4D/Timepix3_5/local_residuals/LocalResidualsY";
    std::string hist_tpx6LocalResidualsX = "Tracking4D/Timepix3_6/local_residuals/LocalResidualsX";
    std::string hist_tpx6LocalResidualsY = "Tracking4D/Timepix3_6/local_residuals/LocalResidualsY";

    // Read the histograms from the file and assign them to varaibles
    TH1F* h0 = static_cast<TH1F*>(f1->Get(hist_tpx0LocalResidualsX.c_str()));
    TH1F* h1 = static_cast<TH1F*>(f1->Get(hist_tpx1LocalResidualsX.c_str()));
    TH1F* h2 = static_cast<TH1F*>(f1->Get(hist_tpx2LocalResidualsX.c_str()));
    TH1F* h3 = static_cast<TH1F*>(f1->Get(hist_tpx3LocalResidualsX.c_str()));
    TH1F* h4 = static_cast<TH1F*>(f1->Get(hist_tpx4LocalResidualsX.c_str()));
    TH1F* h5 = static_cast<TH1F*>(f1->Get(hist_tpx5LocalResidualsX.c_str()));
    TH1F* h6 = static_cast<TH1F*>(f1->Get(hist_tpx6LocalResidualsX.c_str()));
    TH1F* h7 = static_cast<TH1F*>(f1->Get(hist_tpx0LocalResidualsY.c_str()));
    TH1F* h8 = static_cast<TH1F*>(f1->Get(hist_tpx1LocalResidualsY.c_str()));
    TH1F* h9 = static_cast<TH1F*>(f1->Get(hist_tpx2LocalResidualsY.c_str()));
    TH1F* h10 = static_cast<TH1F*>(f1->Get(hist_tpx3LocalResidualsY.c_str()));
    TH1F* h11 = static_cast<TH1F*>(f1->Get(hist_tpx4LocalResidualsY.c_str()));
    TH1F* h12 = static_cast<TH1F*>(f1->Get(hist_tpx5LocalResidualsY.c_str()));
    TH1F* h13 = static_cast<TH1F*>(f1->Get(hist_tpx6LocalResidualsY.c_str()));
    
    TH1F* trackChisqBefore = static_cast<TH1F*>(f1->Get(hist_trackChiSqndof.c_str()));
    
    // For after: use the other file
    TH1F* h0_after = static_cast<TH1F*>(f2->Get(hist_tpx0LocalResidualsX.c_str()));
    TH1F* h1_after = static_cast<TH1F*>(f2->Get(hist_tpx1LocalResidualsX.c_str()));
    TH1F* h2_after = static_cast<TH1F*>(f2->Get(hist_tpx2LocalResidualsX.c_str()));
    TH1F* h3_after = static_cast<TH1F*>(f2->Get(hist_tpx3LocalResidualsX.c_str()));
    TH1F* h4_after = static_cast<TH1F*>(f2->Get(hist_tpx4LocalResidualsX.c_str()));
    TH1F* h5_after = static_cast<TH1F*>(f2->Get(hist_tpx5LocalResidualsX.c_str()));
    TH1F* h6_after = static_cast<TH1F*>(f2->Get(hist_tpx6LocalResidualsX.c_str()));
    TH1F* h7_after = static_cast<TH1F*>(f2->Get(hist_tpx0LocalResidualsY.c_str()));
    TH1F* h8_after = static_cast<TH1F*>(f2->Get(hist_tpx1LocalResidualsY.c_str()));
    TH1F* h9_after = static_cast<TH1F*>(f2->Get(hist_tpx2LocalResidualsY.c_str()));
    TH1F* h10_after = static_cast<TH1F*>(f2->Get(hist_tpx3LocalResidualsY.c_str()));
    TH1F* h11_after = static_cast<TH1F*>(f2->Get(hist_tpx4LocalResidualsY.c_str()));
    TH1F* h12_after = static_cast<TH1F*>(f2->Get(hist_tpx5LocalResidualsY.c_str()));
    TH1F* h13_after = static_cast<TH1F*>(f2->Get(hist_tpx6LocalResidualsY.c_str()));
    
    TH1F* trackChisqAfter = static_cast<TH1F*>(f2->Get(hist_trackChiSqndof.c_str()));

    // Create a new canvas (background to paint on, like when painting a portrait):
    // 1000, 600 defines the size
    TCanvas* c1 = new TCanvas("LocalResiduals x","LocalResiduals x",1000,600);

    // Split canvas into 4x2:
    c1->Divide(4,2);

    // Access first section on canvas:
    c1->cd(1);
    // Rename the histogram and the axis labels:
    h0->SetTitle("Timepix3_0: LocalResiduals x");
    h0->GetXaxis()->SetTitle("x_{track} - x");
    h0->GetYaxis()->SetTitle("Counts");
    // Draw the histogram:
    h0_after->SetLineColor(kRed);
    h0_after->DrawNormalized();
    h0->DrawNormalized("same");
    
    TLegend *leg0 = new TLegend(0.52,0.8,0.9,0.9);
    leg0->AddEntry(h0,"Before telescope alignment");
    leg0->AddEntry(h0_after,"After telescope alignment");
    leg0->Draw();

    // Remove the so-called stat box from the top right:
    gStyle->SetOptStat(0);

    // Access second section on canvas:
    c1->cd(2);

    h1->SetTitle("Timepix3_1: LocalResiduals x");
    h1->GetXaxis()->SetTitle("x_{track} - x");
    h1->GetYaxis()->SetTitle("Counts");
    h1_after->SetLineColor(kRed);
    h1_after->DrawNormalized();
    h1->DrawNormalized("same");
    
    TLegend *leg1 = new TLegend(0.52,0.8,0.9,0.9);
    leg1->AddEntry(h1,"Before telescope alignment");
    leg1->AddEntry(h1_after,"After telescope alignment");
    leg1->Draw();
    
    c1->cd(3);
    h2->SetTitle("Timepix3_2: LocalResiduals x");
    h2->GetXaxis()->SetTitle("x_{track} - x");
    h2->GetYaxis()->SetTitle("Counts");
    h2_after->SetLineColor(kRed);
    h2_after->DrawNormalized();
    h2->DrawNormalized("same");
    
    TLegend *leg2 = new TLegend(0.52,0.8,0.9,0.9);
    leg2->AddEntry(h2,"Before telescope alignment");
    leg2->AddEntry(h2_after,"After telescope alignment");
    leg2->Draw();
    
    c1->cd(4);
    h3->SetTitle("Timepix3_3: LocalResiduals x");
    h3->GetXaxis()->SetTitle("x_{track} - x");
    h3->GetYaxis()->SetTitle("Counts");
    h3_after->SetLineColor(kRed);
    h3_after->DrawNormalized("same");
    h3->DrawNormalized("same");
    
    TLegend *leg3 = new TLegend(0.52,0.8,0.9,0.9);
    leg3->AddEntry(h3,"Before telescope alignment");
    leg3->AddEntry(h3_after,"After telescope alignment");
    leg3->Draw();
    
    c1->cd(5);
    h4->SetTitle("Timepix3_4: LocalResiduals x");
    h4->GetXaxis()->SetTitle("x_{track} - x");
    h4->GetYaxis()->SetTitle("Counts");
    h4_after->SetLineColor(kRed);
    h4_after->DrawNormalized("same");
    h4->DrawNormalized("same");
    
    TLegend *leg4 = new TLegend(0.52,0.8,0.9,0.9);
    leg4->AddEntry(h4,"Before telescope alignment");
    leg4->AddEntry(h4_after,"After telescope alignment");
    leg4->Draw();
    
    c1->cd(6);
    h5->SetTitle("Timepix3_5: LocalResiduals x");
    h5->GetXaxis()->SetTitle("x_{track} - x");
    h5->GetYaxis()->SetTitle("Counts");
    h5_after->SetLineColor(kRed);
    h5_after->DrawNormalized();
    h5->DrawNormalized("same");
    
    TLegend *leg5 = new TLegend(0.52,0.8,0.9,0.9);
    leg5->AddEntry(h5,"Before telescope alignment");
    leg5->AddEntry(h5_after,"After telescope alignment");
    leg5->Draw();
    
    c1->cd(7);
    h6->SetTitle("Timepix3_6: LocalResiduals x");
    h6->GetXaxis()->SetTitle("x_{ref} - x");
    h6->GetYaxis()->SetTitle("Counts");
    h6_after->SetLineColor(kRed);
    h6_after->DrawNormalized();
    h6->DrawNormalized("same");
    
    TLegend *leg6 = new TLegend(0.52,0.8,0.9,0.9);
    leg6->AddEntry(h6,"Before telescope alignment");
    leg6->AddEntry(h6_after,"After telescope alignment");
    leg6->Draw();

    // Save the canvas (i.e. everything drawn onto it) to PDF:
    c1->SaveAs("PDFs/07-analysis_resX.pdf");
    
    
    // ------- Now for correlations in y -------
    
    // Create a new canvas (background to paint on, like when painting a portrait):
    // 1000, 600 defines the size
    TCanvas* c2 = new TCanvas("LocalResiduals y","LocalResiduals y",1000,600);

    // Split canvas into 4x2:
    c2->Divide(4,2);

    // Access first section on canvas:
    c2->cd(1);
    // Rename the histogram and the axis labels:
    h7->SetTitle("Timepix3_0: LocalResiduals y");
    h7->GetXaxis()->SetTitle("y_{track} - y");
    h7->GetYaxis()->SetTitle("Counts");
    // Draw the histogram:
    h7_after->SetLineColor(kRed);
    h7_after->DrawNormalized();
    h7->DrawNormalized("same");
    
    TLegend *leg7 = new TLegend(0.52,0.8,0.9,0.9);
    leg7->AddEntry(h7,"Before telescope alignment");
    leg7->AddEntry(h7_after,"After telescope alignment");
    leg7->Draw();

    // Remove the so-called stat boy from the top right:
    gStyle->SetOptStat(0);

    // Access second section on canvas:
    c2->cd(2);

    h8->SetTitle("Timepix3_1: LocalResiduals y");
    h8->GetXaxis()->SetTitle("y_{track} - y");
    h8->GetYaxis()->SetTitle("Counts");
    h8_after->SetLineColor(kRed);
    h8_after->DrawNormalized();
    h8->DrawNormalized("same");
    
    TLegend *leg8 = new TLegend(0.52,0.8,0.9,0.9);
    leg8->AddEntry(h8,"Before telescope alignment");
    leg8->AddEntry(h8_after,"After telescope alignment");
    leg8->Draw();
    
    c2->cd(3);
    h9->SetTitle("Timepix3_2: LocalResiduals y");
    h9->GetXaxis()->SetTitle("y_{track} - y");
    h9->GetYaxis()->SetTitle("Counts");
    h9_after->SetLineColor(kRed);
    h9_after->DrawNormalized();
    h9->DrawNormalized("same");
    
    TLegend *leg9 = new TLegend(0.52,0.8,0.9,0.9);
    leg9->AddEntry(h9,"Before telescope alignment");
    leg9->AddEntry(h9_after,"After telescope alignment");
    leg9->Draw();
    
    c2->cd(4);
    h10->SetTitle("Timepix10_3: LocalResiduals y");
    h10->GetXaxis()->SetTitle("y_{track} - y");
    h10->GetYaxis()->SetTitle("Counts");
    h10_after->SetLineColor(kRed);
    h10_after->DrawNormalized();
    h10->DrawNormalized("same");
    
    TLegend *leg10 = new TLegend(0.52,0.8,0.9,0.9);
    leg10->AddEntry(h10,"Before telescope alignment");
    leg10->AddEntry(h10_after,"After telescope alignment");
    leg10->Draw();
    
    c2->cd(5);
    h11->SetTitle("Timepix3_4: LocalResiduals y");
    h11->GetXaxis()->SetTitle("y_{track} - y");
    h11->GetYaxis()->SetTitle("Counts");
    h11_after->SetLineColor(kRed);
    h11_after->DrawNormalized();
    h11->DrawNormalized("same");
    
    TLegend *leg11 = new TLegend(0.52,0.8,0.9,0.9);
    leg11->AddEntry(h11,"Before telescope alignment");
    leg11->AddEntry(h11_after,"After telescope alignment");
    leg11->Draw();
    
    c2->cd(6);
    h12->SetTitle("Timepix3_5: LocalResiduals y");
    h12->GetXaxis()->SetTitle("y_{track} - y");
    h12->GetYaxis()->SetTitle("Counts");
    h12_after->SetLineColor(kRed);
    h12_after->DrawNormalized();
    h12->DrawNormalized("same");
    
    TLegend *leg12 = new TLegend(0.52,0.8,0.9,0.9);
    leg12->AddEntry(h12,"Before telescope alignment");
    leg12->AddEntry(h12_after,"After telescope alignment");
    leg12->Draw();
    
    c2->cd(7);
    h13->SetTitle("Timepix3_6: LocalResiduals y");
    h13->GetXaxis()->SetTitle("y_{track} - y");
    h13->GetYaxis()->SetTitle("Counts");
    h13_after->SetLineColor(kRed);
    h13_after->DrawNormalized();
    h13->DrawNormalized("same");
    
    TLegend *leg13 = new TLegend(0.52,0.8,0.9,0.9);
    leg13->AddEntry(h13,"Before telescope alignment");
    leg13->AddEntry(h13_after,"After telescope alignment");
    leg13->Draw();
    

    // Save the canvas (i.e. everything drawn onto it) to PDF:
    c2->SaveAs("PDFs/07-analysis_resY.pdf");
    
    TCanvas* c3 = new TCanvas("Track chisq/ndof","Track chisq/ndof",800,600);
    trackChisqAfter->SetLineColor(kRed);
    trackChisqAfter->DrawNormalized();
    trackChisqBefore->DrawNormalized("same");
    
    TLegend *leg14 = new TLegend(0.5,0.8,0.9,0.9);
    leg14->AddEntry(trackChisqBefore,"Before telescope alignment");
    leg14->AddEntry(trackChisqAfter,"After telescope alignment");
    leg14->Draw();
    
    // Save the canvas (i.e. everything drawn onto it) to PDF:
    c3->SaveAs("PDFs/07-analysis_trackChiSq.pdf");
}
