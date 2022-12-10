#include "GildedRose.h"


GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}
auto brie = "Aged Brie";
auto backstage = "Backstage passes to a TAFKAL80ETC concert";
auto sulfuras = "Sulfuras, Hand of Ragnaros";
void GildedRose::updateQuality()
{
    for(int i = 0; i < items.size(); i++)
    {
        if(items[i].name != brie && items[i].name != backstage && items[i].name != sulfuras && items[i].quality > 0)
        {       
            items[i].quality--;                 
        }
        else if(items[i].quality < 50 && items[i].quality > 0 && items[i].name != sulfuras) 
        {
            items[i].quality++;

            if(items[i].name == backstage && items[i].sellIn < 11 ) 
            {     
                items[i].quality++;
                if(items[i].sellIn < 6)
                {
                    items[i].quality++;
                }
            }
            
        }

        if(items[i].name != sulfuras)
        {
            items[i].sellIn--;
            
        }

        if(items[i].sellIn < 0 && items[i].name != brie && items[i].name != backstage)
        {             
                items[i].quality--;    
        }
        else if(items[i].sellIn < 0 && items[i].name != brie)
            {
                items[i].quality = 0;
            }
        else if(items[i].sellIn < 0 && items[i].quality < 50)
            {  
                items[i].quality++;                
            }
    }
}
