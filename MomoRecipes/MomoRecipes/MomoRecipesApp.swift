//
//  MomoRecipesApp.swift
//  MomoRecipes
//
//  Created by Mahonri Ray on 10/7/23.
//

import SwiftUI

@main
struct MomoRecipesApp: App {
    @StateObject var recipesViewModel = RecipesViewModel()
    var body: some Scene {
        WindowGroup {
            ContentView()
                .environmentObject(recipesViewModel)
        }
    }
}
