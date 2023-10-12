//
//  FavoritesView.swift
//  MomoRecipes
//
//  Created by Mahonri Ray on 10/7/23.
//

import SwiftUI

struct FavoritesView: View {
    var body: some View {
        NavigationView {
            Text("You haven't saved any recipes to your Favorites yet.")
                .navigationTitle("Favorites")
                .padding()
        }
        .navigationViewStyle(.stack)
    }
}

struct FavoritesView_Previews: PreviewProvider {
    static var previews: some View {
        FavoritesView()
    }
}
