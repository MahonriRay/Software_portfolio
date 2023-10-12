//
//  SettingsView.swift
//  MomoRecipes
//
//  Created by Mahonri Ray on 10/7/23.
//

import SwiftUI

struct SettingsView: View {
    var body: some View {
        NavigationStack {
            Text("V1.0.0")
                .navigationTitle("Settings")
        }
        .navigationViewStyle(.stack)
    }
}

struct SettingsView_Previews: PreviewProvider {
    static var previews: some View {
        SettingsView()
    }
}
