#include <filesystem>
#include <iostream>

// Important: The name of the file needs to
// be identical to the name of the function:
void E3_analysis() {
    // std::cout << std::filesystem::current_path() << std::endl;

    // Define the name of the input file:
    // * "../output" means go into parent directory and then into 'output'
    std::string fileName = "../output/03_clustering.root";

    // Open the file
    TFile *f1 = TFile::Open(fileName.c_str());

    // Set the name of the histogram we want to draw:
    // * make sure that the name matches exactly to the one you see in the TBrowser
    std::string hist_tpx2ClusterSize = "Clustering4D/Timepix3_6/clusterSize";
    std::string hist_tpx2ClusterSeedToT = "Clustering4D/Timepix3_6/clusterSeedCharge";
    std::string hist_tpx2ClusterToT = "Clustering4D/Timepix3_6/clusterCharge";
    
    std::string hist_dutClusterSize = "Clustering4D/ATLASpix_0/clusterSize";
    std::string hist_dutClusterSeedToT = "Clustering4D/ATLASpix_0/clusterSeedCharge";
    std::string hist_dutClusterToT = "Clustering4D/ATLASpix_0/clusterCharge";
    std::string hist_dutClusterWidthCol = "Clustering4D/ATLASpix_0/clusterWidthColumn";
    std::string hist_dutClusterWidthRow = "Clustering4D/ATLASpix_0/clusterWidthRow";
    

    // Read the histograms from the file and assign it to varaibles
    TH1F* h_tpx2ClusterSize = static_cast<TH1F*>(f1->Get(hist_tpx2ClusterSize.c_str()));
    TH1F* h_tpx2ClusterSeedToT = static_cast<TH1F*>(f1->Get(hist_tpx2ClusterSeedToT.c_str()));
    TH1F* h_tpx2ClusterToT = static_cast<TH1F*>(f1->Get(hist_tpx2ClusterToT.c_str()));
    
    TH1F* h_dutClusterSize = static_cast<TH1F*>(f1->Get(hist_dutClusterSize.c_str()));
    TH1F* h_dutClusterSeedToT = static_cast<TH1F*>(f1->Get(hist_dutClusterSeedToT.c_str()));
    TH1F* h_dutClusterToT = static_cast<TH1F*>(f1->Get(hist_dutClusterToT.c_str()));
    TH1F* h_dutClusterWidthCol = static_cast<TH1F*>(f1->Get(hist_dutClusterWidthCol.c_str()));
    TH1F* h_dutClusterWidthRow = static_cast<TH1F*>(f1->Get(hist_dutClusterWidthRow.c_str()));
    
    // Create a new canvas
    TCanvas* c1 = new TCanvas("Cluster size","Cluster size",800,600);

    // Rename the histogram and the axis labels:
    h_tpx2ClusterSize->SetTitle("Cluster size");
    h_tpx2ClusterSize->GetXaxis()->SetTitle("Cluster size");
    h_tpx2ClusterSize->GetYaxis()->SetTitle("Counts");
    // Draw the histograms:
    h_tpx2ClusterSize->Draw();
    //Make the second histogram red
    h_dutClusterSize->SetLineColor(kRed);
    h_dutClusterSize->Draw("same"); // same to draw it in the same plot
    
    // Zoom in on the x-axis
    h_tpx2ClusterSize->GetXaxis()->SetRangeUser(0,20);
    
    // Adjust margin so z-axis label is not cut off:
    gPad->SetLeftMargin(0.12);
    
    // Create a legend:
    //         This defines the position: (xmin, ymin, xmax, ymax)
    TLegend *leg = new TLegend(0.5,0.8,0.9,0.9);
    //                 This defines the text in the legend:
    leg->AddEntry(h_tpx2ClusterSize,"sensor: Timepix3_6");
    leg->AddEntry(h_dutClusterSize,"sensor: ATLASpix");
    // Draw the legend:
    leg->Draw();
    
    // Remove the so-called stat box from the top right:
    gStyle->SetOptStat(0);

    // Save the canvas (i.e. everything drawn onto it) to PDF:
    c1->SaveAs("../PDFs/06-analysis_1.pdf");
    
    
    // Create a new canvas
    TCanvas* c2 = new TCanvas("Cluster width","Cluster width",800,600);

    // Rename the histogram and the axis labels:
    h_dutClusterWidthCol->SetTitle("Cluster width");
    h_dutClusterWidthCol->GetXaxis()->SetTitle("Width [pixels]");
    h_dutClusterWidthCol->GetYaxis()->SetTitle("Counts");
    // Draw the histograms:
    h_dutClusterWidthCol->Draw();
    //Make the second histogram red
    h_dutClusterWidthRow->SetLineColor(kRed);
    h_dutClusterWidthRow->Draw("same"); // same to draw it in the same plot
    
    // Zoom in on the x-axis
    h_dutClusterWidthCol->GetXaxis()->SetRangeUser(0,6);
    
    // Adjust margin so z-axis label is not cut off:
    gPad->SetLeftMargin(0.12);
    
    TLegend *leg2 = new TLegend(0.5,0.8,0.9,0.9);
    //                 This defines the text in the legend:
    leg2->AddEntry(h_dutClusterWidthCol,"Cluster width column");
    leg2->AddEntry(h_dutClusterWidthRow,"Cluster width row");
    // Draw the legend:
    leg2->Draw();

    // Save the canvas (i.e. everything drawn onto it) to PDF:
    c2->SaveAs("../PDFs/06-analysis_0.pdf");
    
    
    // Create a new canvas
    TCanvas* c3 = new TCanvas("Cluster ToT","Cluster ToT",1000,600);
    // Split canvas into 2x1:
    c3->Divide(2,1);
    c3->cd(1);

    // Rename the histogram and the axis labels:
    h_dutClusterSeedToT->SetTitle("Cluster ToT, ATLASpix");
    h_dutClusterSeedToT->GetXaxis()->SetTitle("ToT [clock cycles]");
    h_dutClusterSeedToT->GetYaxis()->SetTitle("Counts");
    // Draw the histograms:
    h_dutClusterSeedToT->Draw();
    //Make the second histogram red
    h_dutClusterToT->SetLineColor(kRed);
    h_dutClusterToT->Draw("same"); // same to draw it in the same plot
    
    // Zoom in on the x-axis
    h_dutClusterSeedToT->GetXaxis()->SetRangeUser(0,30);
    
    // Adjust margin so z-axis label is not cut off:
    gPad->SetLeftMargin(0.12);
    
    TLegend *leg3 = new TLegend(0.5,0.8,0.9,0.9);
    //                 This defines the text in the legend:
    leg3->AddEntry(h_dutClusterSeedToT,"Cluster seed ToT");
    leg3->AddEntry(h_dutClusterToT,"Cluster ToT");
    // Draw the legend:
    leg3->Draw();
    
    c3->cd(2);
    h_tpx2ClusterSeedToT->SetTitle("Cluster ToT, Timepix3_6");
    h_tpx2ClusterSeedToT->GetXaxis()->SetTitle("ToT [clock cycles]");
    h_tpx2ClusterSeedToT->GetYaxis()->SetTitle("Counts");
    // Draw the histograms:
    h_tpx2ClusterSeedToT->Draw();
    //Make the second histogram red
    h_tpx2ClusterToT->SetLineColor(kRed);
    h_tpx2ClusterToT->Draw("same"); // same to draw it in the same plot
    
    // Zoom in on the x-axis
    //h_tpx2ClusterToT->GetXaxis()->SetRangeUser(0,255);
    
    
    // Adjust margin so z-axis label is not cut off:
    gPad->SetLeftMargin(0.12);
    
    TLegend *leg4 = new TLegend(0.5,0.8,0.9,0.9);
    //                 This defines the text in the legend:
    leg4->AddEntry(h_tpx2ClusterSeedToT,"Cluster seed ToT");
    leg4->AddEntry(h_tpx2ClusterToT,"Cluster ToT");
    // Draw the legend:
    leg4->Draw();

    // Save the canvas (i.e. everything drawn onto it) to PDF:
    c3->SaveAs("../PDFs/06-analysis_3.pdf");
}
