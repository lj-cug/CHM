
#include "module_factory.hpp"



module_base* module_factory::get(std::string ID, pt::ptree config)
{
    LOG_DEBUG << "Module ID=" << ID;
    
    module_base* mod = nullptr;
    
    if (ID == "slope_iswr")
        mod = new slope_iswr(config);
    else if (ID == "Marsh_shading_iswr")
        mod = new Marsh_shading_iswr(config);
    else if (ID == "const_llra_ta")
        mod = new const_llra_ta(config);
    else if (ID == "Liston_monthly_llra_ta")
        mod = new Liston_monthly_llra_ta(config);
    else if (ID == "Kunkel_monthlyTd_rh")
        mod = new Kunkel_monthlyTd_rh(config);
    else if (ID == "Sicart_ilwr")
        mod = new Sicart_ilwr(config);
    else if (ID == "Liston_wind")
        mod = new Liston_wind(config);
    else if (ID == "PenmanMonteith_evaporation")
        mod = new PenmanMonteith_evaporation(config);
    else if (ID == "Walcek_cloud")
        mod = new Walcek_cloud(config);
    else if (ID == "Harder_precip_phase")
        mod = new Harder_precip_phase(config);
    else if (ID == "Burridge_iswr")
        mod = new Burridge_iswr(config);
    else if (ID == "Iqbal_iswr")
        mod = new Iqbal_iswr(config);
    else if (ID == "iswr_from_obs")
        mod = new iswr_from_obs(config);
    else if (ID == "Dodson_NSA_ta")
        mod = new Dodson_NSA_ta(config);
    else if (ID == "Thornton_p")
        mod = new Thornton_p(config);
    else if (ID == "Thornton_var_p")
        mod = new Thornton_var_p(config);
    else if (ID == "rh_from_obs")
        mod = new rh_from_obs(config);
    else if (ID == "kunkel_rh")
        mod = new kunkel_rh(config);
    else if (ID == "snobal")
        mod = new snobal(config);
    else if (ID == "Richard_albedo")
        mod = new Richard_albedo(config);

    if(mod == nullptr)
    {
        BOOST_THROW_EXCEPTION(module_not_found() 
                              << errstr_info( std::string("Module not found ") + ID)
                        );
    }

    mod->ID = ID;
    mod->cfg = config;
    
    return mod;

}
