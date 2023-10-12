//
//  RecipeModel.swift
//  MomoRecipes
//
//  Created by Mahonri Ray on 10/7/23.
//

import Foundation

enum Category : String, CaseIterable, Identifiable{
    var id: String {self.rawValue}
    
    case breakfast = "Breakfast"
    case soup = "Soup"
    case salad = "Salad"
    case appetizer = "Appetizer"
    case main = "Main"
    case side = "Side"
    case dessert = "Dessert"
    case snack = "Snack"
    case drink = "Drink"
}

struct Recipe: Identifiable{
    let id = UUID()
    let name : String
    let image : String
    let description : String
    let ingredients : String
    let directions : String
    let category : Category.RawValue
    let datePublished : String
    let url : String
}

extension Recipe{
    static let all: [Recipe] = [
    Recipe(name: "ButterScotch Cookies",
           image: "https://thesaltymarshmallow.com/wp-content/uploads/2017/06/butterscotch-chip-cookies1.jpg",
           description: "Cookies made with butterscotch chips, tres yummy",
           ingredients: "Sugar \nFlour \nEgg",
           directions: "Do stuff, yo",
           category: "Dessert",
           datePublished: "2023-10-07",
           url: "None"),
    Recipe(name: "Mac & Cheese",
           image: "https://sugarspunrun.com/wp-content/uploads/2023/03/Easy-mac-and-cheese-recipe-1-of-1.jpg",
           description: "It's Mac & Cheese, you know the vibes",
           ingredients: "16 oz. Macaroni Noodles \nCheese \nLess Sodium Chicken Broth",
           directions: "Do Mac & Cheese stuff, yo",
           category: "Side",
           datePublished: "2023-10-07",
           url: "None")
    ]
}
