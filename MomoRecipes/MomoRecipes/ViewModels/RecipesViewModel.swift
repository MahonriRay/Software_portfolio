//
//  RecipesViewModel.swift
//  MomoRecipes
//
//  Created by Mahonri Ray on 10/8/23.
//

import Foundation

class RecipesViewModel: ObservableObject {
    @Published private(set) var recipes: [Recipe] = []
    
    init() {
        recipes = Recipe.all
    }
    
    func addRecipe(recipe: Recipe){
        recipes.append(recipe)
    }
}
