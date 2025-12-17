
// Important: The name of the file needs to
// be identical to the name of the function:
void E2_analysis() {

    // Define the name of the input file:
    // * "../output" means go into parent directory and then into 'output'
    std::string fileName = "../output/02_read_data.root";

    // Open the file
    TFile *f1 = TFile::Open(fileName.c_str());

    // Set the name of the histogram we want to draw:
    // * make sure that the name matches exactly to the one you see in the TBrowser
    std::string hist_tpx0ToT = "EventLoaderTimepix3/Timepix3_0/pixelToT";
    std::string hist_tpx0HitMap = "EventLoaderTimepix3/Timepix3_0/hitMap";
    std::string hist_tpx1ToT = "EventLoaderTimepix3/Timepix3_1/pixelToT";
    std::string hist_tpx1HitMap = "EventLoaderTimepix3/Timepix3_1/hitMap";
    std::string hist_tpx2ToT = "EventLoaderTimepix3/Timepix3_2/pixelToT";
    std::string hist_tpx2HitMap = "EventLoaderTimepix3/Timepix3_2/hitMap";
    std::string hist_tpx3ToT = "EventLoaderTimepix3/Timepix3_3/pixelToT";
    std::string hist_tpx3HitMap = "EventLoaderTimepix3/Timepix3_3/hitMap";
    std::string hist_tpx4ToT = "EventLoaderTimepix3/Timepix3_4/pixelToT";
    std::string hist_tpx4HitMap = "EventLoaderTimepix3/Timepix3_4/hitMap";
    std::string hist_tpx5ToT = "EventLoaderTimepix3/Timepix3_5/pixelToT";
    std::string hist_tpx5HitMap = "EventLoaderTimepix3/Timepix3_5/hitMap";
    std::string hist_tpx6ToT = "EventLoaderTimepix3/Timepix3_6/pixelToT";
    std::string hist_tpx6HitMap = "EventLoaderTimepix3/Timepix3_6/hitMap";
    
    std::string hist_dutToT = "EventLoaderATLASpix/DUT/pixelToT";
    std::string hist_dutHitMap = "EventLoaderATLASpix/DUT/hitMap";

    // Read the histograms from the file and assign it to varaibles
    TH1F* h0 = static_cast<TH1F*>(f1->Get(hist_tpx0HitMap.c_str()));
    TH1F* h1 = static_cast<TH1F*>(f1->Get(hist_tpx1HitMap.c_str()));
    TH1F* h2 = static_cast<TH1F*>(f1->Get(hist_tpx2HitMap.c_str()));
    TH1F* h3 = static_cast<TH1F*>(f1->Get(hist_tpx3HitMap.c_str()));
    TH1F* h4 = static_cast<TH1F*>(f1->Get(hist_tpx4HitMap.c_str()));
    TH1F* h5 = static_cast<TH1F*>(f1->Get(hist_tpx5HitMap.c_str()));
    TH1F* h6 = static_cast<TH1F*>(f1->Get(hist_tpx6HitMap.c_str()));
    
    TH1F* hDUT = static_cast<TH1F*>(f1->Get(hist_dutHitMap.c_str()));

    // Create a new canvas (background to paint on, like when painting a portrait):
    // 1000, 600 defines the size
    TCanvas* c1 = new TCanvas("c1","c1",1000,600);

    // Split canvas into 4x2:
    c1->Divide(4,2);

    // Access first section on canvas:
    c1->cd(1);
    // Rename the histogram and the axis labels:
    h0->SetTitle("Timepix3_0: Hitmap");
    h0->GetXaxis()->SetTitle("x [pixels]");
    h0->GetYaxis()->SetTitle("y [pixels]");
    // Draw the histogram:
    h0->Draw("colz"); // colz: draw with color scale
    
    // Make the colour axis thinner
    gPad->Update();
    TPaletteAxis * pal = (TPaletteAxis*)h0->GetListOfFunctions()->FindObject("palette");
    auto width = 8;
    pal->SetX2(pal->GetX1() + width);

    // Remove the so-called stat box from the top right:
    gStyle->SetOptStat(0);

    // Access second section on canvas:
    c1->cd(2);

    h1->SetTitle("Timepix3_1: Hitmap");
    h1->GetXaxis()->SetTitle("x [pixels]");
    h1->GetYaxis()->SetTitle("y [pixels]");
    // Draw the second histogram:
    h1->Draw("colz"); // colz: draw with color scale
    
    gPad->Update();
    pal = (TPaletteAxis*)h1->GetListOfFunctions()->FindObject("palette");
    pal->SetX2(pal->GetX1() + width);
    
    c1->cd(3);
    h2->SetTitle("Timepix3_2: Hitmap");
    h2->GetXaxis()->SetTitle("x [pixels]");
    h2->GetYaxis()->SetTitle("y [pixels]");
    h2->Draw("colz");
    gPad->Update();
    pal = (TPaletteAxis*)h2->GetListOfFunctions()->FindObject("palette");
    pal->SetX2(pal->GetX1() + width);
    
    c1->cd(4);
    hDUT->SetTitle("ATLASpix: Hitmap");
    hDUT->GetXaxis()->SetTitle("x [pixels]");
    hDUT->GetYaxis()->SetTitle("y [pixels]");
    hDUT->Draw("colz");
    gPad->Update();
    pal = (TPaletteAxis*)hDUT->GetListOfFunctions()->FindObject("palette");
    pal->SetX2(pal->GetX1() + 1);
    
    c1->cd(5);
    h3->SetTitle("Timepix3_3: Hitmap");
    h3->GetXaxis()->SetTitle("x [pixels]");
    h3->GetYaxis()->SetTitle("y [pixels]");
    h3->Draw("colz");
    gPad->Update();
    pal = (TPaletteAxis*)h3->GetListOfFunctions()->FindObject("palette");
    pal->SetX2(pal->GetX1() + width);
    
    c1->cd(6);
    h4->SetTitle("Timepix3_4: Hitmap");
    h4->GetXaxis()->SetTitle("x [pixels]");
    h4->GetYaxis()->SetTitle("y [pixels]");
    h4->Draw("colz");
    gPad->Update();
    pal = (TPaletteAxis*)h4->GetListOfFunctions()->FindObject("palette");
    pal->SetX2(pal->GetX1() + width);
    
    c1->cd(7);
    h5->SetTitle("Timepix3_5: Hitmap");
    h5->GetXaxis()->SetTitle("x [pixels]");
    h5->GetYaxis()->SetTitle("y [pixels]");
    h5->Draw("colz");
    gPad->Update();
    pal = (TPaletteAxis*)h5->GetListOfFunctions()->FindObject("palette");
    pal->SetX2(pal->GetX1() + width);
    
    c1->cd(8);
    h6->SetTitle("Timepix3_6: Hitmap");
    h6->GetXaxis()->SetTitle("x [pixels]");
    h6->GetYaxis()->SetTitle("y [pixels]");
    h6->Draw("colz");
    gPad->Update();
    pal = (TPaletteAxis*)h6->GetListOfFunctions()->FindObject("palette");
    pal->SetX2(pal->GetX1() + width);

    // Save the canvas (i.e. everything drawn onto it) to PDF:
    c1->SaveAs("PDFs/02-analysis.pdf");
}
