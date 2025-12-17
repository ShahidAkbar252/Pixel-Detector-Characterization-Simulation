
// Important: The name of the file needs to
// be identical to the name of the function:
void E5_analysis() {

    // Define the name of the input file:
    // * "../output" means go into parent directory and then into 'output'
    // Before prealignment:
    std::string fileName_before = "../output/04_correlations.root";
    std::string fileName_after = "../output/05_prealignment.root";

    // Open the files
    TFile *f1 = TFile::Open(fileName_before.c_str());
    TFile *f2 = TFile::Open(fileName_after.c_str());

    // Set the name of the histogram we want to draw:
    // * make sure that the name matches exactly to the one you see in the TBrowser
    std::string hist_tpx0CorrelationX = "Correlations/Timepix3_0/correlationX";
    std::string hist_tpx0CorrelationY = "Correlations/Timepix3_0/correlationY";
    std::string hist_tpx1CorrelationX = "Correlations/Timepix3_1/correlationX";
    std::string hist_tpx1CorrelationY = "Correlations/Timepix3_1/correlationY";
    std::string hist_tpx2CorrelationX = "Correlations/Timepix3_2/correlationX";
    std::string hist_tpx2CorrelationY = "Correlations/Timepix3_2/correlationY";
    std::string hist_tpx3CorrelationX = "Correlations/Timepix3_3/correlationX";
    std::string hist_tpx3CorrelationY = "Correlations/Timepix3_3/correlationY";
    std::string hist_tpx4CorrelationX = "Correlations/Timepix3_4/correlationX";
    std::string hist_tpx4CorrelationY = "Correlations/Timepix3_4/correlationY";
    std::string hist_tpx5CorrelationX = "Correlations/Timepix3_5/correlationX";
    std::string hist_tpx5CorrelationY = "Correlations/Timepix3_5/correlationY";
    std::string hist_tpx6CorrelationX = "Correlations/Timepix3_6/correlationX";
    std::string hist_tpx6CorrelationY = "Correlations/Timepix3_6/correlationY";
    
    std::string hist_dutCorrelationX = "Correlations/ATLASpix_0/correlationX";
    std::string hist_dutCorrelationY = "Correlations/ATLASpix_0/correlationY";

    // Read the histograms from the file and assign them to varaibles
    TH1F* h0 = static_cast<TH1F*>(f1->Get(hist_tpx0CorrelationX.c_str()));
    TH1F* h1 = static_cast<TH1F*>(f1->Get(hist_tpx1CorrelationX.c_str()));
    TH1F* h2 = static_cast<TH1F*>(f1->Get(hist_tpx2CorrelationX.c_str()));
    TH1F* h3 = static_cast<TH1F*>(f1->Get(hist_tpx3CorrelationX.c_str()));
    TH1F* h4 = static_cast<TH1F*>(f1->Get(hist_tpx4CorrelationX.c_str()));
    TH1F* h5 = static_cast<TH1F*>(f1->Get(hist_tpx5CorrelationX.c_str()));
    TH1F* h6 = static_cast<TH1F*>(f1->Get(hist_tpx6CorrelationX.c_str()));
    TH1F* h7 = static_cast<TH1F*>(f1->Get(hist_tpx0CorrelationY.c_str()));
    TH1F* h8 = static_cast<TH1F*>(f1->Get(hist_tpx1CorrelationY.c_str()));
    TH1F* h9 = static_cast<TH1F*>(f1->Get(hist_tpx2CorrelationY.c_str()));
    TH1F* h10 = static_cast<TH1F*>(f1->Get(hist_tpx3CorrelationY.c_str()));
    TH1F* h11 = static_cast<TH1F*>(f1->Get(hist_tpx4CorrelationY.c_str()));
    TH1F* h12 = static_cast<TH1F*>(f1->Get(hist_tpx5CorrelationY.c_str()));
    TH1F* h13 = static_cast<TH1F*>(f1->Get(hist_tpx6CorrelationY.c_str()));
    
    TH1F* hDUT_X = static_cast<TH1F*>(f1->Get(hist_dutCorrelationX.c_str()));
    TH1F* hDUT_Y = static_cast<TH1F*>(f1->Get(hist_dutCorrelationY.c_str()));
    
    // For after: use the other file
    TH1F* h0_after = static_cast<TH1F*>(f2->Get(hist_tpx0CorrelationX.c_str()));
    TH1F* h1_after = static_cast<TH1F*>(f2->Get(hist_tpx1CorrelationX.c_str()));
    TH1F* h2_after = static_cast<TH1F*>(f2->Get(hist_tpx2CorrelationX.c_str()));
    TH1F* h3_after = static_cast<TH1F*>(f2->Get(hist_tpx3CorrelationX.c_str()));
    TH1F* h4_after = static_cast<TH1F*>(f2->Get(hist_tpx4CorrelationX.c_str()));
    TH1F* h5_after = static_cast<TH1F*>(f2->Get(hist_tpx5CorrelationX.c_str()));
    TH1F* h6_after = static_cast<TH1F*>(f2->Get(hist_tpx6CorrelationX.c_str()));
    TH1F* h7_after = static_cast<TH1F*>(f2->Get(hist_tpx0CorrelationY.c_str()));
    TH1F* h8_after = static_cast<TH1F*>(f2->Get(hist_tpx1CorrelationY.c_str()));
    TH1F* h9_after = static_cast<TH1F*>(f2->Get(hist_tpx2CorrelationY.c_str()));
    TH1F* h10_after = static_cast<TH1F*>(f2->Get(hist_tpx3CorrelationY.c_str()));
    TH1F* h11_after = static_cast<TH1F*>(f2->Get(hist_tpx4CorrelationY.c_str()));
    TH1F* h12_after = static_cast<TH1F*>(f2->Get(hist_tpx5CorrelationY.c_str()));
    TH1F* h13_after = static_cast<TH1F*>(f2->Get(hist_tpx6CorrelationY.c_str()));
    
    TH1F* hDUT_X_after = static_cast<TH1F*>(f2->Get(hist_dutCorrelationX.c_str()));
    TH1F* hDUT_Y_after = static_cast<TH1F*>(f2->Get(hist_dutCorrelationY.c_str()));

    // Create a new canvas (background to paint on, like when painting a portrait):
    // 1000, 600 defines the size
    TCanvas* c1 = new TCanvas("Correlations x","Correlations x",1000,600);

    // Split canvas into 4x2:
    c1->Divide(4,2);

    // Access first section on canvas:
    c1->cd(1);
    // Rename the histogram and the axis labels:
    h0->SetTitle("Timepix3_0: Correlations x");
    h0->GetXaxis()->SetTitle("x_{ref} - x");
    h0->GetYaxis()->SetTitle("Counts");
    // Draw the histogram:
    h0->Draw();
    h0_after->SetLineColor(kRed);
    h0_after->Draw("same");
    
    TLegend *leg0 = new TLegend(0.5,0.8,0.9,0.9);
    leg0->AddEntry(h0,"Before prealignment");
    leg0->AddEntry(h0_after,"After prealignment");
    leg0->Draw();

    // Remove the so-called stat box from the top right:
    gStyle->SetOptStat(0);

    // Access second section on canvas:
    c1->cd(2);

    h1->SetTitle("Timepix3_1: Correlations x");
    h1->GetXaxis()->SetTitle("x_{ref} - x");
    h1->GetYaxis()->SetTitle("Counts");
    // Draw the second histogram:
    h1->Draw();
    h1_after->SetLineColor(kRed);
    h1_after->Draw("same");
    
    TLegend *leg1 = new TLegend(0.5,0.8,0.9,0.9);
    leg1->AddEntry(h1,"Before prealignment");
    leg1->AddEntry(h1_after,"After prealignment");
    leg1->Draw();
    
    c1->cd(3);
    h2->SetTitle("Timepix3_2: Correlations x");
    h2->GetXaxis()->SetTitle("x_{ref} - x");
    h2->GetYaxis()->SetTitle("Counts");
    h2->Draw();
    h2_after->SetLineColor(kRed);
    h2_after->Draw("same");
    
    TLegend *leg2 = new TLegend(0.5,0.8,0.9,0.9);
    leg2->AddEntry(h2,"Before prealignment");
    leg2->AddEntry(h2_after,"After prealignment");
    leg2->Draw();
    
    c1->cd(4);
    hDUT_X->SetTitle("ATLASpix: Correlations x");
    hDUT_X->GetXaxis()->SetTitle("x_{ref} - x");
    hDUT_X->GetYaxis()->SetTitle("Counts");
    hDUT_X->Draw();
    hDUT_X_after->SetLineColor(kRed);
    hDUT_X_after->Draw("same");
    
    TLegend *legDUT = new TLegend(0.5,0.8,0.9,0.9);
    legDUT->AddEntry(hDUT_X,"Before prealignment");
    legDUT->AddEntry(hDUT_X_after,"After prealignment");
    legDUT->Draw();
    
    c1->cd(5);
    h3->SetTitle("Timepix3_3: Correlations x");
    h3->GetXaxis()->SetTitle("x_{ref} - x");
    h3->GetYaxis()->SetTitle("Counts");
    h3->Draw();
    h3_after->SetLineColor(kRed);
    h3_after->Draw("same");
    
    TLegend *leg3 = new TLegend(0.5,0.8,0.9,0.9);
    leg3->AddEntry(h3,"Before prealignment");
    leg3->AddEntry(h3_after,"After prealignment");
    leg3->Draw();
    
    c1->cd(6);
    h4->SetTitle("Timepix3_4: Correlations x");
    h4->GetXaxis()->SetTitle("x_{ref} - x");
    h4->GetYaxis()->SetTitle("Counts");
    h4->Draw();
    h4_after->SetLineColor(kRed);
    h4_after->Draw("same");
    
    TLegend *leg4 = new TLegend(0.5,0.8,0.9,0.9);
    leg4->AddEntry(h4,"Before prealignment");
    leg4->AddEntry(h4_after,"After prealignment");
    leg4->Draw();
    
    c1->cd(7);
    h5->SetTitle("Timepix3_5: Correlations x");
    h5->GetXaxis()->SetTitle("x_{ref} - x");
    h5->GetYaxis()->SetTitle("Counts");
    h5->Draw();
    h5_after->SetLineColor(kRed);
    h5_after->Draw("same");
    
    TLegend *leg5 = new TLegend(0.5,0.8,0.9,0.9);
    leg5->AddEntry(h5,"Before prealignment");
    leg5->AddEntry(h5_after,"After prealignment");
    leg5->Draw();
    
    c1->cd(8);
    h6->SetTitle("Timepix3_6: Correlations x");
    h6->GetXaxis()->SetTitle("x_{ref} - x");
    h6->GetYaxis()->SetTitle("Counts");
    h6->Draw();
    h6_after->SetLineColor(kRed);
    h6_after->Draw("same");
    
    TLegend *leg6 = new TLegend(0.5,0.8,0.9,0.9);
    leg6->AddEntry(h6,"Before prealignment");
    leg6->AddEntry(h6_after,"After prealignment");
    leg6->Draw();

    // Save the canvas (i.e. everything drawn onto it) to PDF:
    c1->SaveAs("../PDFs/05-analysis_corrX.pdf");
    
    
    // ------- Now for correlations in y -------
    
    // Create a new canvas (background to paint on, like when painting a portrait):
    // 1000, 600 defines the size
    TCanvas* c2 = new TCanvas("Correlations y","Correlations y",1000,600);

    // Split canvas into 4x2:
    c2->Divide(4,2);

    // Access first section on canvas:
    c2->cd(1);
    // Rename the histogram and the axis labels:
    h7->SetTitle("Timepix3_0: Correlations y");
    h7->GetXaxis()->SetTitle("y_{ref} - y");
    h7->GetYaxis()->SetTitle("Counts");
    // Draw the histogram:
    h7->Draw();
    h7_after->SetLineColor(kRed);
    h7_after->Draw("same");
    
    TLegend *leg7 = new TLegend(7.5,7.8,7.9,7.9);
    leg7->AddEntry(h7,"Before prealignment");
    leg7->AddEntry(h7_after,"After prealignment");
    leg7->Draw();

    // Remove the so-called stat boy from the top right:
    gStyle->SetOptStat(0);

    // Access second section on canvas:
    c2->cd(2);

    h8->SetTitle("Timepix3_1: Correlations y");
    h8->GetXaxis()->SetTitle("y_{ref} - y");
    h8->GetYaxis()->SetTitle("Counts");
    // Draw the second histogram:
    h8->Draw();
    h8_after->SetLineColor(kRed);
    h8_after->Draw("same");
    
    TLegend *leg8 = new TLegend(0.5,0.8,0.9,0.9);
    leg8->AddEntry(h8,"Before prealignment");
    leg8->AddEntry(h8_after,"After prealignment");
    leg8->Draw();
    
    c2->cd(3);
    h9->SetTitle("Timepix3_2: Correlations y");
    h9->GetXaxis()->SetTitle("y_{ref} - y");
    h9->GetYaxis()->SetTitle("Counts");
    h9->Draw();
    h9_after->SetLineColor(kRed);
    h9_after->Draw("same");
    
    TLegend *leg9 = new TLegend(0.5,0.8,0.9,0.9);
    leg9->AddEntry(h9,"Before prealignment");
    leg9->AddEntry(h9_after,"After prealignment");
    leg9->Draw();
    
    c2->cd(4);
    hDUT_Y->SetTitle("ATLASpix: Correlations y");
    hDUT_Y->GetXaxis()->SetTitle("y_{ref} - y");
    hDUT_Y->GetYaxis()->SetTitle("Counts");
    hDUT_Y->Draw();
    hDUT_Y_after->SetLineColor(kRed);
    hDUT_Y_after->Draw("same");
    
    TLegend *legDUT_Y = new TLegend(0.5,0.8,0.9,0.9);
    legDUT_Y->AddEntry(hDUT_Y,"Before prealignment");
    legDUT_Y->AddEntry(hDUT_Y_after,"After prealignment");
    legDUT_Y->Draw();
    
    c2->cd(5);
    h10->SetTitle("Timepix10_3: Correlations y");
    h10->GetXaxis()->SetTitle("y_{ref} - y");
    h10->GetYaxis()->SetTitle("Counts");
    h10->Draw();
    h10_after->SetLineColor(kRed);
    h10_after->Draw("same");
    
    TLegend *leg10 = new TLegend(0.5,0.8,0.9,0.9);
    leg10->AddEntry(h10,"Before prealignment");
    leg10->AddEntry(h10_after,"After prealignment");
    leg10->Draw();
    
    c2->cd(6);
    h11->SetTitle("Timepix3_4: Correlations y");
    h11->GetXaxis()->SetTitle("y_{ref} - y");
    h11->GetYaxis()->SetTitle("Counts");
    h11->Draw();
    h11_after->SetLineColor(kRed);
    h11_after->Draw("same");
    
    TLegend *leg11 = new TLegend(0.5,0.8,0.9,0.9);
    leg11->AddEntry(h11,"Before prealignment");
    leg11->AddEntry(h11_after,"After prealignment");
    leg11->Draw();
    
    c2->cd(7);
    h12->SetTitle("Timepix3_5: Correlations y");
    h12->GetXaxis()->SetTitle("y_{ref} - y");
    h12->GetYaxis()->SetTitle("Counts");
    h12->Draw();
    h12_after->SetLineColor(kRed);
    h12_after->Draw("same");
    
    TLegend *leg12 = new TLegend(0.12,0.8,0.9,0.9);
    leg12->AddEntry(h12,"Before prealignment");
    leg12->AddEntry(h12_after,"After prealignment");
    leg12->Draw();
    
    c2->cd(8);
    h13->SetTitle("Timepix3_6: Correlations y");
    h13->GetXaxis()->SetTitle("y_{ref} - y");
    h13->GetYaxis()->SetTitle("Counts");
    h13->Draw();
    h13_after->SetLineColor(kRed);
    h13_after->Draw("same");
    
    TLegend *leg13 = new TLegend(0.5,0.8,0.9,0.9);
    leg13->AddEntry(h13,"Before prealignment");
    leg13->AddEntry(h13_after,"After prealignment");
    leg13->Draw();
    

    // Save the canvas (i.e. everything drawn onto it) to PDF:
    c2->SaveAs("../PDFs/05-analysis_corrY.pdf");
}
