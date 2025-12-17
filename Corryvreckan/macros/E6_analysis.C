
// Important: The name of the file needs to
// be identical to the name of the function:
void E6_analysis() {

    // Define the name of the input file:
    // * "../output" means go into parent directory and then into 'output'
    // Before prealignment:
    std::string fileName = "../output/06_tracking.root";

    // Open the files
    TFile *f1 = TFile::Open(fileName.c_str());

    // Set the name of the histogram we want to draw:
    // * make sure that the name matches exactly to the one you see in the TBrowser
    std::string hist_tpx3CorrelationX = "Correlations/Timepix3_3/correlationX";
    std::string hist_tpx3CorrelationY = "Correlations/Timepix3_3/correlationY";
    
    std::string hist_tpx3ResidualX = "Tracking4D/Timepix3_3/local_residuals/LocalResidualsX";
    std::string hist_tpx3ResidualY = "Tracking4D/Timepix3_3/local_residuals/LocalResidualsY";
    
    std::string hist_trackChiSqndof = "Tracking4D/trackChi2ndof";

    // Read the histograms from the file and assign them to varaibles
    TH1F* h0 = static_cast<TH1F*>(f1->Get(hist_tpx3CorrelationX.c_str()));
    TH1F* h1 = static_cast<TH1F*>(f1->Get(hist_tpx3CorrelationY.c_str()));
    TH1F* h2 = static_cast<TH1F*>(f1->Get(hist_tpx3ResidualX.c_str()));
    TH1F* h3 = static_cast<TH1F*>(f1->Get(hist_tpx3ResidualY.c_str()));
    TH1F* h4 = static_cast<TH1F*>(f1->Get(hist_trackChiSqndof.c_str()));

    // Create a new canvas (background to paint on, like when painting a portrait):
    // 1000, 600 defines the size
    TCanvas* c1 = new TCanvas("First tracking","First tracking",2400,600);

    // Split canvas into 3x1:
    c1->Divide(3,1);

    // Access first section on canvas:
    c1->cd(1);
    // Rename the histogram and the axis labels:
    h0->SetTitle("Timepix3_3: Correlations");
    h0->GetXaxis()->SetTitle("Ref - pos");
    h0->GetYaxis()->SetTitle("Counts");
    // Draw the histogram:
    h0->Draw();
    h1->SetLineColor(kRed);
    h1->Draw("same");
    
    TLegend *leg0 = new TLegend(0.5,0.8,0.9,0.9);
    leg0->AddEntry(h0,"Correlation x");
    leg0->AddEntry(h1,"Correlation y");
    leg0->Draw();

    // Remove the so-called stat box from the top right:
    gStyle->SetOptStat(0);

    // Access second section on canvas:
    c1->cd(2);

    h2->SetTitle("Timepix3_3: Local residuals");
    h2->GetXaxis()->SetTitle("Track - reco");
    h2->GetYaxis()->SetTitle("Counts");
    // Draw the second histogram:
    h2->Draw();
    h3->SetLineColor(kRed);
    h3->Draw("same");
    
    TLegend *leg1 = new TLegend(0.5,0.8,0.9,0.9);
    leg1->AddEntry(h2,"Local residual in x");
    leg1->AddEntry(h3,"Local residual in y");
    leg1->Draw();
    
    c1->cd(3);
    h4->Draw();

    // Save the canvas (i.e. everything drawn onto it) to PDF:
    c1->SaveAs("PDFs/06-analysis_corrVsResidual.pdf");
}
