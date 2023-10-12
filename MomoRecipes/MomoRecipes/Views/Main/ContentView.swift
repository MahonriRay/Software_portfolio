//
//  ContentView.swift
//  MomoRecipes
//
//  Created by Mahonri Ray on 10/7/23.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        TabBar()
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
            .environmentObject(RecipesViewModel())
    }
}
