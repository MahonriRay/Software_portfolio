//
//  NewRecipeView.swift
//  MomoRecipes
//
//  Created by Mahonri Ray on 10/7/23.
//

import SwiftUI

struct NewRecipeView: View {
    @State private var showAddRecipe = false
    var body: some View {
        NavigationView {
            Button("Add Recipe Manually"){
                showAddRecipe = true
            }
                .navigationTitle("New Recipe")
        }
        .navigationViewStyle(.stack)
        .sheet(isPresented: $showAddRecipe) {
            AddRecipeView()
        }
    }
}

struct NewRecipeView_Previews: PreviewProvider {
    static var previews: some View {
        NewRecipeView()
    }
}
