// This file was automatically generated and should not be edited.
#pragma once

#include <memory>
#include <vector>
#include "nlohmann/json.hpp"
#include <optional>
#include <variant>

// optional serialization
namespace nlohmann {
    template <typename T>
    struct adl_serializer<std::optional<T>> {
        static void to_json(json & json, std::optional<T> const & opt) {
            if (opt.has_value()) {
                json = *opt;
            } else {
                json = nullptr;
            }
        }

        static void from_json(const json & json, std::optional<T> & opt) {
            if (json.is_null()) {
                opt.reset();
            } else {
                opt = json.get<T>();
            }
        }
    };
}

namespace shopify {

    using Json = nlohmann::json;
    using Id = std::string;
    using std::optional;
    using std::variant;
    using std::monostate;
    using std::visit;

    enum class Operation { Query, Mutation, Subscription };

    struct GraphqlError {
        std::string message;
    };

    template <typename Data>
    using GraphqlResponse = variant<Data, std::vector<GraphqlError>>;

    inline void from_json(Json const & json, GraphqlError & value) {
        json.at("message").get_to(value.message);
    }

    // Represents a generic custom attribute.
    struct Attribute {
        // Key or name of the attribute.
        std::string key;
        // Value of the attribute.
        optional<std::string> value;
    };

    inline void from_json(Json const & json, Attribute & value) {
        json.at("key").get_to(value.key);
        {
            auto it = json.find("value");
            if (it != json.end()) {
                it->get_to(value.value);
            } else {
                value.value.reset();
            }
        }
    }

    // Key-value pairs that contains additional information.
    struct AttributeOutput {
        // Key or name of the attribute.
        std::string key;
        // Value of the attribute.
        std::string value;
    };

    inline void to_json(Json & json, AttributeOutput const & value) {
        json["key"] = value.key;
        json["value"] = value.value;
    }

    struct CartLineInput {
        // The ID of the cart line.
        Id cartLineId;
        // The quantity of the cart line to be merged.The max quantity is 2000.
        int32_t quantity;
    };

    inline void to_json(Json & json, CartLineInput const & value) {
        json["cartLineId"] = value.cartLineId;
        json["quantity"] = value.quantity;
    }

    // Represents whether the product is a member of the given collection.
    struct CollectionMembership {
        // The ID of the collection.
        Id collectionId;
        // Whether the product is a member of the collection.
        bool isMember;
    };

    inline void from_json(Json const & json, CollectionMembership & value) {
        json.at("collectionId").get_to(value.collectionId);
        json.at("isMember").get_to(value.isMember);
    }

    // A company's main point of contact.
    struct CompanyContact {
        /*
        The date and time ([ISO 8601 format](http://en.wikipedia.org/wiki/ISO_8601))
        at which the company contact was created in Shopify.
        */
        std::string createdAt;
        // The ID of the company.
        Id id;
        // The company contact's locale (language).
        optional<std::string> locale;
        // The company contact's job title.
        optional<std::string> title;
        /*
        The date and time ([ISO 8601 format](http://en.wikipedia.org/wiki/ISO_8601))
        at which the company contact was last modified.
        */
        std::string updatedAt;
    };

    inline void from_json(Json const & json, CompanyContact & value) {
        json.at("createdAt").get_to(value.createdAt);
        json.at("id").get_to(value.id);
        {
            auto it = json.find("locale");
            if (it != json.end()) {
                it->get_to(value.locale);
            } else {
                value.locale.reset();
            }
        }
        {
            auto it = json.find("title");
            if (it != json.end()) {
                it->get_to(value.title);
            } else {
                value.title.reset();
            }
        }
        json.at("updatedAt").get_to(value.updatedAt);
    }

    /*
    The code designating a country/region, which generally follows ISO 3166-1 alpha-2 guidelines.
    If a territory doesn't have a country code value in the `CountryCode` enum, then it might be considered a subdivision
    of another country. For example, the territories associated with Spain are represented by the country code `ES`,
    and the territories associated with the United States of America are represented by the country code `US`.
    */
    enum class CountryCode {
        // Ascension Island.
        Ac,
        // Andorra.
        Ad,
        // United Arab Emirates.
        Ae,
        // Afghanistan.
        Af,
        // Antigua & Barbuda.
        Ag,
        // Anguilla.
        Ai,
        // Albania.
        Al,
        // Armenia.
        Am,
        // Netherlands Antilles.
        An,
        // Angola.
        Ao,
        // Argentina.
        Ar,
        // Austria.
        At,
        // Australia.
        Au,
        // Aruba.
        Aw,
        // Åland Islands.
        Ax,
        // Azerbaijan.
        Az,
        // Bosnia & Herzegovina.
        Ba,
        // Barbados.
        Bb,
        // Bangladesh.
        Bd,
        // Belgium.
        Be,
        // Burkina Faso.
        Bf,
        // Bulgaria.
        Bg,
        // Bahrain.
        Bh,
        // Burundi.
        Bi,
        // Benin.
        Bj,
        // St. Barthélemy.
        Bl,
        // Bermuda.
        Bm,
        // Brunei.
        Bn,
        // Bolivia.
        Bo,
        // Caribbean Netherlands.
        Bq,
        // Brazil.
        Br,
        // Bahamas.
        Bs,
        // Bhutan.
        Bt,
        // Bouvet Island.
        Bv,
        // Botswana.
        Bw,
        // Belarus.
        By,
        // Belize.
        Bz,
        // Canada.
        Ca,
        // Cocos (Keeling) Islands.
        Cc,
        // Congo - Kinshasa.
        Cd,
        // Central African Republic.
        Cf,
        // Congo - Brazzaville.
        Cg,
        // Switzerland.
        Ch,
        // Côte d’Ivoire.
        Ci,
        // Cook Islands.
        Ck,
        // Chile.
        Cl,
        // Cameroon.
        Cm,
        // China.
        Cn,
        // Colombia.
        Co,
        // Costa Rica.
        Cr,
        // Cuba.
        Cu,
        // Cape Verde.
        Cv,
        // Curaçao.
        Cw,
        // Christmas Island.
        Cx,
        // Cyprus.
        Cy,
        // Czechia.
        Cz,
        // Germany.
        De,
        // Djibouti.
        Dj,
        // Denmark.
        Dk,
        // Dominica.
        Dm,
        // Dominican Republic.
        Do,
        // Algeria.
        Dz,
        // Ecuador.
        Ec,
        // Estonia.
        Ee,
        // Egypt.
        Eg,
        // Western Sahara.
        Eh,
        // Eritrea.
        Er,
        // Spain.
        Es,
        // Ethiopia.
        Et,
        // Finland.
        Fi,
        // Fiji.
        Fj,
        // Falkland Islands.
        Fk,
        // Faroe Islands.
        Fo,
        // France.
        Fr,
        // Gabon.
        Ga,
        // United Kingdom.
        Gb,
        // Grenada.
        Gd,
        // Georgia.
        Ge,
        // French Guiana.
        Gf,
        // Guernsey.
        Gg,
        // Ghana.
        Gh,
        // Gibraltar.
        Gi,
        // Greenland.
        Gl,
        // Gambia.
        Gm,
        // Guinea.
        Gn,
        // Guadeloupe.
        Gp,
        // Equatorial Guinea.
        Gq,
        // Greece.
        Gr,
        // South Georgia & South Sandwich Islands.
        Gs,
        // Guatemala.
        Gt,
        // Guinea-Bissau.
        Gw,
        // Guyana.
        Gy,
        // Hong Kong SAR.
        Hk,
        // Heard & McDonald Islands.
        Hm,
        // Honduras.
        Hn,
        // Croatia.
        Hr,
        // Haiti.
        Ht,
        // Hungary.
        Hu,
        // Indonesia.
        Id,
        // Ireland.
        Ie,
        // Israel.
        Il,
        // Isle of Man.
        Im,
        // India.
        In,
        // British Indian Ocean Territory.
        Io,
        // Iraq.
        Iq,
        // Iran.
        Ir,
        // Iceland.
        Is,
        // Italy.
        It,
        // Jersey.
        Je,
        // Jamaica.
        Jm,
        // Jordan.
        Jo,
        // Japan.
        Jp,
        // Kenya.
        Ke,
        // Kyrgyzstan.
        Kg,
        // Cambodia.
        Kh,
        // Kiribati.
        Ki,
        // Comoros.
        Km,
        // St. Kitts & Nevis.
        Kn,
        // North Korea.
        Kp,
        // South Korea.
        Kr,
        // Kuwait.
        Kw,
        // Cayman Islands.
        Ky,
        // Kazakhstan.
        Kz,
        // Laos.
        La,
        // Lebanon.
        Lb,
        // St. Lucia.
        Lc,
        // Liechtenstein.
        Li,
        // Sri Lanka.
        Lk,
        // Liberia.
        Lr,
        // Lesotho.
        Ls,
        // Lithuania.
        Lt,
        // Luxembourg.
        Lu,
        // Latvia.
        Lv,
        // Libya.
        Ly,
        // Morocco.
        Ma,
        // Monaco.
        Mc,
        // Moldova.
        Md,
        // Montenegro.
        Me,
        // St. Martin.
        Mf,
        // Madagascar.
        Mg,
        // North Macedonia.
        Mk,
        // Mali.
        Ml,
        // Myanmar (Burma).
        Mm,
        // Mongolia.
        Mn,
        // Macao SAR.
        Mo,
        // Martinique.
        Mq,
        // Mauritania.
        Mr,
        // Montserrat.
        Ms,
        // Malta.
        Mt,
        // Mauritius.
        Mu,
        // Maldives.
        Mv,
        // Malawi.
        Mw,
        // Mexico.
        Mx,
        // Malaysia.
        My,
        // Mozambique.
        Mz,
        // Namibia.
        Na,
        // New Caledonia.
        Nc,
        // Niger.
        Ne,
        // Norfolk Island.
        Nf,
        // Nigeria.
        Ng,
        // Nicaragua.
        Ni,
        // Netherlands.
        Nl,
        // Norway.
        No,
        // Nepal.
        Np,
        // Nauru.
        Nr,
        // Niue.
        Nu,
        // New Zealand.
        Nz,
        // Oman.
        Om,
        // Panama.
        Pa,
        // Peru.
        Pe,
        // French Polynesia.
        Pf,
        // Papua New Guinea.
        Pg,
        // Philippines.
        Ph,
        // Pakistan.
        Pk,
        // Poland.
        Pl,
        // St. Pierre & Miquelon.
        Pm,
        // Pitcairn Islands.
        Pn,
        // Palestinian Territories.
        Ps,
        // Portugal.
        Pt,
        // Paraguay.
        Py,
        // Qatar.
        Qa,
        // Réunion.
        Re,
        // Romania.
        Ro,
        // Serbia.
        Rs,
        // Russia.
        Ru,
        // Rwanda.
        Rw,
        // Saudi Arabia.
        Sa,
        // Solomon Islands.
        Sb,
        // Seychelles.
        Sc,
        // Sudan.
        Sd,
        // Sweden.
        Se,
        // Singapore.
        Sg,
        // St. Helena.
        Sh,
        // Slovenia.
        Si,
        // Svalbard & Jan Mayen.
        Sj,
        // Slovakia.
        Sk,
        // Sierra Leone.
        Sl,
        // San Marino.
        Sm,
        // Senegal.
        Sn,
        // Somalia.
        So,
        // Suriname.
        Sr,
        // South Sudan.
        Ss,
        // São Tomé & Príncipe.
        St,
        // El Salvador.
        Sv,
        // Sint Maarten.
        Sx,
        // Syria.
        Sy,
        // Eswatini.
        Sz,
        // Tristan da Cunha.
        Ta,
        // Turks & Caicos Islands.
        Tc,
        // Chad.
        Td,
        // French Southern Territories.
        Tf,
        // Togo.
        Tg,
        // Thailand.
        Th,
        // Tajikistan.
        Tj,
        // Tokelau.
        Tk,
        // Timor-Leste.
        Tl,
        // Turkmenistan.
        Tm,
        // Tunisia.
        Tn,
        // Tonga.
        To,
        // Türkiye.
        Tr,
        // Trinidad & Tobago.
        Tt,
        // Tuvalu.
        Tv,
        // Taiwan.
        Tw,
        // Tanzania.
        Tz,
        // Ukraine.
        Ua,
        // Uganda.
        Ug,
        // U.S. Outlying Islands.
        Um,
        // United States.
        Us,
        // Uruguay.
        Uy,
        // Uzbekistan.
        Uz,
        // Vatican City.
        Va,
        // St. Vincent & Grenadines.
        Vc,
        // Venezuela.
        Ve,
        // British Virgin Islands.
        Vg,
        // Vietnam.
        Vn,
        // Vanuatu.
        Vu,
        // Wallis & Futuna.
        Wf,
        // Samoa.
        Ws,
        // Kosovo.
        Xk,
        // Yemen.
        Ye,
        // Mayotte.
        Yt,
        // South Africa.
        Za,
        // Zambia.
        Zm,
        // Zimbabwe.
        Zw,
        // Unknown Region.
        Zz,
        Unknown = -1
    };

    NLOHMANN_JSON_SERIALIZE_ENUM(CountryCode, {
        {CountryCode::Unknown, nullptr},
        {CountryCode::Ac, "AC"},
        {CountryCode::Ad, "AD"},
        {CountryCode::Ae, "AE"},
        {CountryCode::Af, "AF"},
        {CountryCode::Ag, "AG"},
        {CountryCode::Ai, "AI"},
        {CountryCode::Al, "AL"},
        {CountryCode::Am, "AM"},
        {CountryCode::An, "AN"},
        {CountryCode::Ao, "AO"},
        {CountryCode::Ar, "AR"},
        {CountryCode::At, "AT"},
        {CountryCode::Au, "AU"},
        {CountryCode::Aw, "AW"},
        {CountryCode::Ax, "AX"},
        {CountryCode::Az, "AZ"},
        {CountryCode::Ba, "BA"},
        {CountryCode::Bb, "BB"},
        {CountryCode::Bd, "BD"},
        {CountryCode::Be, "BE"},
        {CountryCode::Bf, "BF"},
        {CountryCode::Bg, "BG"},
        {CountryCode::Bh, "BH"},
        {CountryCode::Bi, "BI"},
        {CountryCode::Bj, "BJ"},
        {CountryCode::Bl, "BL"},
        {CountryCode::Bm, "BM"},
        {CountryCode::Bn, "BN"},
        {CountryCode::Bo, "BO"},
        {CountryCode::Bq, "BQ"},
        {CountryCode::Br, "BR"},
        {CountryCode::Bs, "BS"},
        {CountryCode::Bt, "BT"},
        {CountryCode::Bv, "BV"},
        {CountryCode::Bw, "BW"},
        {CountryCode::By, "BY"},
        {CountryCode::Bz, "BZ"},
        {CountryCode::Ca, "CA"},
        {CountryCode::Cc, "CC"},
        {CountryCode::Cd, "CD"},
        {CountryCode::Cf, "CF"},
        {CountryCode::Cg, "CG"},
        {CountryCode::Ch, "CH"},
        {CountryCode::Ci, "CI"},
        {CountryCode::Ck, "CK"},
        {CountryCode::Cl, "CL"},
        {CountryCode::Cm, "CM"},
        {CountryCode::Cn, "CN"},
        {CountryCode::Co, "CO"},
        {CountryCode::Cr, "CR"},
        {CountryCode::Cu, "CU"},
        {CountryCode::Cv, "CV"},
        {CountryCode::Cw, "CW"},
        {CountryCode::Cx, "CX"},
        {CountryCode::Cy, "CY"},
        {CountryCode::Cz, "CZ"},
        {CountryCode::De, "DE"},
        {CountryCode::Dj, "DJ"},
        {CountryCode::Dk, "DK"},
        {CountryCode::Dm, "DM"},
        {CountryCode::Do, "DO"},
        {CountryCode::Dz, "DZ"},
        {CountryCode::Ec, "EC"},
        {CountryCode::Ee, "EE"},
        {CountryCode::Eg, "EG"},
        {CountryCode::Eh, "EH"},
        {CountryCode::Er, "ER"},
        {CountryCode::Es, "ES"},
        {CountryCode::Et, "ET"},
        {CountryCode::Fi, "FI"},
        {CountryCode::Fj, "FJ"},
        {CountryCode::Fk, "FK"},
        {CountryCode::Fo, "FO"},
        {CountryCode::Fr, "FR"},
        {CountryCode::Ga, "GA"},
        {CountryCode::Gb, "GB"},
        {CountryCode::Gd, "GD"},
        {CountryCode::Ge, "GE"},
        {CountryCode::Gf, "GF"},
        {CountryCode::Gg, "GG"},
        {CountryCode::Gh, "GH"},
        {CountryCode::Gi, "GI"},
        {CountryCode::Gl, "GL"},
        {CountryCode::Gm, "GM"},
        {CountryCode::Gn, "GN"},
        {CountryCode::Gp, "GP"},
        {CountryCode::Gq, "GQ"},
        {CountryCode::Gr, "GR"},
        {CountryCode::Gs, "GS"},
        {CountryCode::Gt, "GT"},
        {CountryCode::Gw, "GW"},
        {CountryCode::Gy, "GY"},
        {CountryCode::Hk, "HK"},
        {CountryCode::Hm, "HM"},
        {CountryCode::Hn, "HN"},
        {CountryCode::Hr, "HR"},
        {CountryCode::Ht, "HT"},
        {CountryCode::Hu, "HU"},
        {CountryCode::Id, "ID"},
        {CountryCode::Ie, "IE"},
        {CountryCode::Il, "IL"},
        {CountryCode::Im, "IM"},
        {CountryCode::In, "IN"},
        {CountryCode::Io, "IO"},
        {CountryCode::Iq, "IQ"},
        {CountryCode::Ir, "IR"},
        {CountryCode::Is, "IS"},
        {CountryCode::It, "IT"},
        {CountryCode::Je, "JE"},
        {CountryCode::Jm, "JM"},
        {CountryCode::Jo, "JO"},
        {CountryCode::Jp, "JP"},
        {CountryCode::Ke, "KE"},
        {CountryCode::Kg, "KG"},
        {CountryCode::Kh, "KH"},
        {CountryCode::Ki, "KI"},
        {CountryCode::Km, "KM"},
        {CountryCode::Kn, "KN"},
        {CountryCode::Kp, "KP"},
        {CountryCode::Kr, "KR"},
        {CountryCode::Kw, "KW"},
        {CountryCode::Ky, "KY"},
        {CountryCode::Kz, "KZ"},
        {CountryCode::La, "LA"},
        {CountryCode::Lb, "LB"},
        {CountryCode::Lc, "LC"},
        {CountryCode::Li, "LI"},
        {CountryCode::Lk, "LK"},
        {CountryCode::Lr, "LR"},
        {CountryCode::Ls, "LS"},
        {CountryCode::Lt, "LT"},
        {CountryCode::Lu, "LU"},
        {CountryCode::Lv, "LV"},
        {CountryCode::Ly, "LY"},
        {CountryCode::Ma, "MA"},
        {CountryCode::Mc, "MC"},
        {CountryCode::Md, "MD"},
        {CountryCode::Me, "ME"},
        {CountryCode::Mf, "MF"},
        {CountryCode::Mg, "MG"},
        {CountryCode::Mk, "MK"},
        {CountryCode::Ml, "ML"},
        {CountryCode::Mm, "MM"},
        {CountryCode::Mn, "MN"},
        {CountryCode::Mo, "MO"},
        {CountryCode::Mq, "MQ"},
        {CountryCode::Mr, "MR"},
        {CountryCode::Ms, "MS"},
        {CountryCode::Mt, "MT"},
        {CountryCode::Mu, "MU"},
        {CountryCode::Mv, "MV"},
        {CountryCode::Mw, "MW"},
        {CountryCode::Mx, "MX"},
        {CountryCode::My, "MY"},
        {CountryCode::Mz, "MZ"},
        {CountryCode::Na, "NA"},
        {CountryCode::Nc, "NC"},
        {CountryCode::Ne, "NE"},
        {CountryCode::Nf, "NF"},
        {CountryCode::Ng, "NG"},
        {CountryCode::Ni, "NI"},
        {CountryCode::Nl, "NL"},
        {CountryCode::No, "NO"},
        {CountryCode::Np, "NP"},
        {CountryCode::Nr, "NR"},
        {CountryCode::Nu, "NU"},
        {CountryCode::Nz, "NZ"},
        {CountryCode::Om, "OM"},
        {CountryCode::Pa, "PA"},
        {CountryCode::Pe, "PE"},
        {CountryCode::Pf, "PF"},
        {CountryCode::Pg, "PG"},
        {CountryCode::Ph, "PH"},
        {CountryCode::Pk, "PK"},
        {CountryCode::Pl, "PL"},
        {CountryCode::Pm, "PM"},
        {CountryCode::Pn, "PN"},
        {CountryCode::Ps, "PS"},
        {CountryCode::Pt, "PT"},
        {CountryCode::Py, "PY"},
        {CountryCode::Qa, "QA"},
        {CountryCode::Re, "RE"},
        {CountryCode::Ro, "RO"},
        {CountryCode::Rs, "RS"},
        {CountryCode::Ru, "RU"},
        {CountryCode::Rw, "RW"},
        {CountryCode::Sa, "SA"},
        {CountryCode::Sb, "SB"},
        {CountryCode::Sc, "SC"},
        {CountryCode::Sd, "SD"},
        {CountryCode::Se, "SE"},
        {CountryCode::Sg, "SG"},
        {CountryCode::Sh, "SH"},
        {CountryCode::Si, "SI"},
        {CountryCode::Sj, "SJ"},
        {CountryCode::Sk, "SK"},
        {CountryCode::Sl, "SL"},
        {CountryCode::Sm, "SM"},
        {CountryCode::Sn, "SN"},
        {CountryCode::So, "SO"},
        {CountryCode::Sr, "SR"},
        {CountryCode::Ss, "SS"},
        {CountryCode::St, "ST"},
        {CountryCode::Sv, "SV"},
        {CountryCode::Sx, "SX"},
        {CountryCode::Sy, "SY"},
        {CountryCode::Sz, "SZ"},
        {CountryCode::Ta, "TA"},
        {CountryCode::Tc, "TC"},
        {CountryCode::Td, "TD"},
        {CountryCode::Tf, "TF"},
        {CountryCode::Tg, "TG"},
        {CountryCode::Th, "TH"},
        {CountryCode::Tj, "TJ"},
        {CountryCode::Tk, "TK"},
        {CountryCode::Tl, "TL"},
        {CountryCode::Tm, "TM"},
        {CountryCode::Tn, "TN"},
        {CountryCode::To, "TO"},
        {CountryCode::Tr, "TR"},
        {CountryCode::Tt, "TT"},
        {CountryCode::Tv, "TV"},
        {CountryCode::Tw, "TW"},
        {CountryCode::Tz, "TZ"},
        {CountryCode::Ua, "UA"},
        {CountryCode::Ug, "UG"},
        {CountryCode::Um, "UM"},
        {CountryCode::Us, "US"},
        {CountryCode::Uy, "UY"},
        {CountryCode::Uz, "UZ"},
        {CountryCode::Va, "VA"},
        {CountryCode::Vc, "VC"},
        {CountryCode::Ve, "VE"},
        {CountryCode::Vg, "VG"},
        {CountryCode::Vn, "VN"},
        {CountryCode::Vu, "VU"},
        {CountryCode::Wf, "WF"},
        {CountryCode::Ws, "WS"},
        {CountryCode::Xk, "XK"},
        {CountryCode::Ye, "YE"},
        {CountryCode::Yt, "YT"},
        {CountryCode::Za, "ZA"},
        {CountryCode::Zm, "ZM"},
        {CountryCode::Zw, "ZW"},
        {CountryCode::Zz, "ZZ"},
    });

    /*
    The three-letter currency codes that represent the world currencies used in
    stores. These include standard ISO 4217 codes, legacy codes,
    and non-standard codes.
    */
    enum class CurrencyCode {
        // United Arab Emirates Dirham (AED).
        Aed,
        // Afghan Afghani (AFN).
        Afn,
        // Albanian Lek (ALL).
        All,
        // Armenian Dram (AMD).
        Amd,
        // Netherlands Antillean Guilder.
        Ang,
        // Angolan Kwanza (AOA).
        Aoa,
        // Argentine Pesos (ARS).
        Ars,
        // Australian Dollars (AUD).
        Aud,
        // Aruban Florin (AWG).
        Awg,
        // Azerbaijani Manat (AZN).
        Azn,
        // Bosnia and Herzegovina Convertible Mark (BAM).
        Bam,
        // Barbadian Dollar (BBD).
        Bbd,
        // Bangladesh Taka (BDT).
        Bdt,
        // Bulgarian Lev (BGN).
        Bgn,
        // Bahraini Dinar (BHD).
        Bhd,
        // Burundian Franc (BIF).
        Bif,
        // Bermudian Dollar (BMD).
        Bmd,
        // Brunei Dollar (BND).
        Bnd,
        // Bolivian Boliviano (BOB).
        Bob,
        // Brazilian Real (BRL).
        Brl,
        // Bahamian Dollar (BSD).
        Bsd,
        // Bhutanese Ngultrum (BTN).
        Btn,
        // Botswana Pula (BWP).
        Bwp,
        // Belarusian Ruble (BYN).
        Byn,
        // Belarusian Ruble (BYR).
        Byr,
        // Belize Dollar (BZD).
        Bzd,
        // Canadian Dollars (CAD).
        Cad,
        // Congolese franc (CDF).
        Cdf,
        // Swiss Francs (CHF).
        Chf,
        // Chilean Peso (CLP).
        Clp,
        // Chinese Yuan Renminbi (CNY).
        Cny,
        // Colombian Peso (COP).
        Cop,
        // Costa Rican Colones (CRC).
        Crc,
        // Cape Verdean escudo (CVE).
        Cve,
        // Czech Koruny (CZK).
        Czk,
        // Djiboutian Franc (DJF).
        Djf,
        // Danish Kroner (DKK).
        Dkk,
        // Dominican Peso (DOP).
        Dop,
        // Algerian Dinar (DZD).
        Dzd,
        // Egyptian Pound (EGP).
        Egp,
        // Eritrean Nakfa (ERN).
        Ern,
        // Ethiopian Birr (ETB).
        Etb,
        // Euro (EUR).
        Eur,
        // Fijian Dollars (FJD).
        Fjd,
        // Falkland Islands Pounds (FKP).
        Fkp,
        // United Kingdom Pounds (GBP).
        Gbp,
        // Georgian Lari (GEL).
        Gel,
        // Ghanaian Cedi (GHS).
        Ghs,
        // Gibraltar Pounds (GIP).
        Gip,
        // Gambian Dalasi (GMD).
        Gmd,
        // Guinean Franc (GNF).
        Gnf,
        // Guatemalan Quetzal (GTQ).
        Gtq,
        // Guyanese Dollar (GYD).
        Gyd,
        // Hong Kong Dollars (HKD).
        Hkd,
        // Honduran Lempira (HNL).
        Hnl,
        // Croatian Kuna (HRK).
        Hrk,
        // Haitian Gourde (HTG).
        Htg,
        // Hungarian Forint (HUF).
        Huf,
        // Indonesian Rupiah (IDR).
        Idr,
        // Israeli New Shekel (NIS).
        Ils,
        // Indian Rupees (INR).
        Inr,
        // Iraqi Dinar (IQD).
        Iqd,
        // Iranian Rial (IRR).
        Irr,
        // Icelandic Kronur (ISK).
        Isk,
        // Jersey Pound.
        Jep,
        // Jamaican Dollars (JMD).
        Jmd,
        // Jordanian Dinar (JOD).
        Jod,
        // Japanese Yen (JPY).
        Jpy,
        // Kenyan Shilling (KES).
        Kes,
        // Kyrgyzstani Som (KGS).
        Kgs,
        // Cambodian Riel.
        Khr,
        // Kiribati Dollar (KID).
        Kid,
        // Comorian Franc (KMF).
        Kmf,
        // South Korean Won (KRW).
        Krw,
        // Kuwaiti Dinar (KWD).
        Kwd,
        // Cayman Dollars (KYD).
        Kyd,
        // Kazakhstani Tenge (KZT).
        Kzt,
        // Laotian Kip (LAK).
        Lak,
        // Lebanese Pounds (LBP).
        Lbp,
        // Sri Lankan Rupees (LKR).
        Lkr,
        // Liberian Dollar (LRD).
        Lrd,
        // Lesotho Loti (LSL).
        Lsl,
        // Lithuanian Litai (LTL).
        Ltl,
        // Latvian Lati (LVL).
        Lvl,
        // Libyan Dinar (LYD).
        Lyd,
        // Moroccan Dirham.
        Mad,
        // Moldovan Leu (MDL).
        Mdl,
        // Malagasy Ariary (MGA).
        Mga,
        // Macedonia Denar (MKD).
        Mkd,
        // Burmese Kyat (MMK).
        Mmk,
        // Mongolian Tugrik.
        Mnt,
        // Macanese Pataca (MOP).
        Mop,
        // Mauritanian Ouguiya (MRU).
        Mru,
        // Mauritian Rupee (MUR).
        Mur,
        // Maldivian Rufiyaa (MVR).
        Mvr,
        // Malawian Kwacha (MWK).
        Mwk,
        // Mexican Pesos (MXN).
        Mxn,
        // Malaysian Ringgits (MYR).
        Myr,
        // Mozambican Metical.
        Mzn,
        // Namibian Dollar.
        Nad,
        // Nigerian Naira (NGN).
        Ngn,
        // Nicaraguan Córdoba (NIO).
        Nio,
        // Norwegian Kroner (NOK).
        Nok,
        // Nepalese Rupee (NPR).
        Npr,
        // New Zealand Dollars (NZD).
        Nzd,
        // Omani Rial (OMR).
        Omr,
        // Panamian Balboa (PAB).
        Pab,
        // Peruvian Nuevo Sol (PEN).
        Pen,
        // Papua New Guinean Kina (PGK).
        Pgk,
        // Philippine Peso (PHP).
        Php,
        // Pakistani Rupee (PKR).
        Pkr,
        // Polish Zlotych (PLN).
        Pln,
        // Paraguayan Guarani (PYG).
        Pyg,
        // Qatari Rial (QAR).
        Qar,
        // Romanian Lei (RON).
        Ron,
        // Serbian dinar (RSD).
        Rsd,
        // Russian Rubles (RUB).
        Rub,
        // Rwandan Franc (RWF).
        Rwf,
        // Saudi Riyal (SAR).
        Sar,
        // Solomon Islands Dollar (SBD).
        Sbd,
        // Seychellois Rupee (SCR).
        Scr,
        // Sudanese Pound (SDG).
        Sdg,
        // Swedish Kronor (SEK).
        Sek,
        // Singapore Dollars (SGD).
        Sgd,
        // Saint Helena Pounds (SHP).
        Shp,
        // Sierra Leonean Leone (SLL).
        Sll,
        // Somali Shilling (SOS).
        Sos,
        // Surinamese Dollar (SRD).
        Srd,
        // South Sudanese Pound (SSP).
        Ssp,
        // Sao Tome And Principe Dobra (STD).
        Std,
        // Sao Tome And Principe Dobra (STN).
        Stn,
        // Syrian Pound (SYP).
        Syp,
        // Swazi Lilangeni (SZL).
        Szl,
        // Thai baht (THB).
        Thb,
        // Tajikistani Somoni (TJS).
        Tjs,
        // Turkmenistani Manat (TMT).
        Tmt,
        // Tunisian Dinar (TND).
        Tnd,
        // Tongan Pa'anga (TOP).
        Top,
        // Turkish Lira (TRY).
        Try,
        // Trinidad and Tobago Dollars (TTD).
        Ttd,
        // Taiwan Dollars (TWD).
        Twd,
        // Tanzanian Shilling (TZS).
        Tzs,
        // Ukrainian Hryvnia (UAH).
        Uah,
        // Ugandan Shilling (UGX).
        Ugx,
        // United States Dollars (USD).
        Usd,
        // Uruguayan Pesos (UYU).
        Uyu,
        // Uzbekistan som (UZS).
        Uzs,
        // Venezuelan Bolivares (VED).
        Ved,
        // Venezuelan Bolivares (VEF).
        Vef,
        // Venezuelan Bolivares Soberanos (VES).
        Ves,
        // Vietnamese đồng (VND).
        Vnd,
        // Vanuatu Vatu (VUV).
        Vuv,
        // Samoan Tala (WST).
        Wst,
        // Central African CFA Franc (XAF).
        Xaf,
        // East Caribbean Dollar (XCD).
        Xcd,
        // West African CFA franc (XOF).
        Xof,
        // CFP Franc (XPF).
        Xpf,
        // Unrecognized currency.
        Xxx,
        // Yemeni Rial (YER).
        Yer,
        // South African Rand (ZAR).
        Zar,
        // Zambian Kwacha (ZMW).
        Zmw,
        Unknown = -1
    };

    NLOHMANN_JSON_SERIALIZE_ENUM(CurrencyCode, {
        {CurrencyCode::Unknown, nullptr},
        {CurrencyCode::Aed, "AED"},
        {CurrencyCode::Afn, "AFN"},
        {CurrencyCode::All, "ALL"},
        {CurrencyCode::Amd, "AMD"},
        {CurrencyCode::Ang, "ANG"},
        {CurrencyCode::Aoa, "AOA"},
        {CurrencyCode::Ars, "ARS"},
        {CurrencyCode::Aud, "AUD"},
        {CurrencyCode::Awg, "AWG"},
        {CurrencyCode::Azn, "AZN"},
        {CurrencyCode::Bam, "BAM"},
        {CurrencyCode::Bbd, "BBD"},
        {CurrencyCode::Bdt, "BDT"},
        {CurrencyCode::Bgn, "BGN"},
        {CurrencyCode::Bhd, "BHD"},
        {CurrencyCode::Bif, "BIF"},
        {CurrencyCode::Bmd, "BMD"},
        {CurrencyCode::Bnd, "BND"},
        {CurrencyCode::Bob, "BOB"},
        {CurrencyCode::Brl, "BRL"},
        {CurrencyCode::Bsd, "BSD"},
        {CurrencyCode::Btn, "BTN"},
        {CurrencyCode::Bwp, "BWP"},
        {CurrencyCode::Byn, "BYN"},
        {CurrencyCode::Byr, "BYR"},
        {CurrencyCode::Bzd, "BZD"},
        {CurrencyCode::Cad, "CAD"},
        {CurrencyCode::Cdf, "CDF"},
        {CurrencyCode::Chf, "CHF"},
        {CurrencyCode::Clp, "CLP"},
        {CurrencyCode::Cny, "CNY"},
        {CurrencyCode::Cop, "COP"},
        {CurrencyCode::Crc, "CRC"},
        {CurrencyCode::Cve, "CVE"},
        {CurrencyCode::Czk, "CZK"},
        {CurrencyCode::Djf, "DJF"},
        {CurrencyCode::Dkk, "DKK"},
        {CurrencyCode::Dop, "DOP"},
        {CurrencyCode::Dzd, "DZD"},
        {CurrencyCode::Egp, "EGP"},
        {CurrencyCode::Ern, "ERN"},
        {CurrencyCode::Etb, "ETB"},
        {CurrencyCode::Eur, "EUR"},
        {CurrencyCode::Fjd, "FJD"},
        {CurrencyCode::Fkp, "FKP"},
        {CurrencyCode::Gbp, "GBP"},
        {CurrencyCode::Gel, "GEL"},
        {CurrencyCode::Ghs, "GHS"},
        {CurrencyCode::Gip, "GIP"},
        {CurrencyCode::Gmd, "GMD"},
        {CurrencyCode::Gnf, "GNF"},
        {CurrencyCode::Gtq, "GTQ"},
        {CurrencyCode::Gyd, "GYD"},
        {CurrencyCode::Hkd, "HKD"},
        {CurrencyCode::Hnl, "HNL"},
        {CurrencyCode::Hrk, "HRK"},
        {CurrencyCode::Htg, "HTG"},
        {CurrencyCode::Huf, "HUF"},
        {CurrencyCode::Idr, "IDR"},
        {CurrencyCode::Ils, "ILS"},
        {CurrencyCode::Inr, "INR"},
        {CurrencyCode::Iqd, "IQD"},
        {CurrencyCode::Irr, "IRR"},
        {CurrencyCode::Isk, "ISK"},
        {CurrencyCode::Jep, "JEP"},
        {CurrencyCode::Jmd, "JMD"},
        {CurrencyCode::Jod, "JOD"},
        {CurrencyCode::Jpy, "JPY"},
        {CurrencyCode::Kes, "KES"},
        {CurrencyCode::Kgs, "KGS"},
        {CurrencyCode::Khr, "KHR"},
        {CurrencyCode::Kid, "KID"},
        {CurrencyCode::Kmf, "KMF"},
        {CurrencyCode::Krw, "KRW"},
        {CurrencyCode::Kwd, "KWD"},
        {CurrencyCode::Kyd, "KYD"},
        {CurrencyCode::Kzt, "KZT"},
        {CurrencyCode::Lak, "LAK"},
        {CurrencyCode::Lbp, "LBP"},
        {CurrencyCode::Lkr, "LKR"},
        {CurrencyCode::Lrd, "LRD"},
        {CurrencyCode::Lsl, "LSL"},
        {CurrencyCode::Ltl, "LTL"},
        {CurrencyCode::Lvl, "LVL"},
        {CurrencyCode::Lyd, "LYD"},
        {CurrencyCode::Mad, "MAD"},
        {CurrencyCode::Mdl, "MDL"},
        {CurrencyCode::Mga, "MGA"},
        {CurrencyCode::Mkd, "MKD"},
        {CurrencyCode::Mmk, "MMK"},
        {CurrencyCode::Mnt, "MNT"},
        {CurrencyCode::Mop, "MOP"},
        {CurrencyCode::Mru, "MRU"},
        {CurrencyCode::Mur, "MUR"},
        {CurrencyCode::Mvr, "MVR"},
        {CurrencyCode::Mwk, "MWK"},
        {CurrencyCode::Mxn, "MXN"},
        {CurrencyCode::Myr, "MYR"},
        {CurrencyCode::Mzn, "MZN"},
        {CurrencyCode::Nad, "NAD"},
        {CurrencyCode::Ngn, "NGN"},
        {CurrencyCode::Nio, "NIO"},
        {CurrencyCode::Nok, "NOK"},
        {CurrencyCode::Npr, "NPR"},
        {CurrencyCode::Nzd, "NZD"},
        {CurrencyCode::Omr, "OMR"},
        {CurrencyCode::Pab, "PAB"},
        {CurrencyCode::Pen, "PEN"},
        {CurrencyCode::Pgk, "PGK"},
        {CurrencyCode::Php, "PHP"},
        {CurrencyCode::Pkr, "PKR"},
        {CurrencyCode::Pln, "PLN"},
        {CurrencyCode::Pyg, "PYG"},
        {CurrencyCode::Qar, "QAR"},
        {CurrencyCode::Ron, "RON"},
        {CurrencyCode::Rsd, "RSD"},
        {CurrencyCode::Rub, "RUB"},
        {CurrencyCode::Rwf, "RWF"},
        {CurrencyCode::Sar, "SAR"},
        {CurrencyCode::Sbd, "SBD"},
        {CurrencyCode::Scr, "SCR"},
        {CurrencyCode::Sdg, "SDG"},
        {CurrencyCode::Sek, "SEK"},
        {CurrencyCode::Sgd, "SGD"},
        {CurrencyCode::Shp, "SHP"},
        {CurrencyCode::Sll, "SLL"},
        {CurrencyCode::Sos, "SOS"},
        {CurrencyCode::Srd, "SRD"},
        {CurrencyCode::Ssp, "SSP"},
        {CurrencyCode::Std, "STD"},
        {CurrencyCode::Stn, "STN"},
        {CurrencyCode::Syp, "SYP"},
        {CurrencyCode::Szl, "SZL"},
        {CurrencyCode::Thb, "THB"},
        {CurrencyCode::Tjs, "TJS"},
        {CurrencyCode::Tmt, "TMT"},
        {CurrencyCode::Tnd, "TND"},
        {CurrencyCode::Top, "TOP"},
        {CurrencyCode::Try, "TRY"},
        {CurrencyCode::Ttd, "TTD"},
        {CurrencyCode::Twd, "TWD"},
        {CurrencyCode::Tzs, "TZS"},
        {CurrencyCode::Uah, "UAH"},
        {CurrencyCode::Ugx, "UGX"},
        {CurrencyCode::Usd, "USD"},
        {CurrencyCode::Uyu, "UYU"},
        {CurrencyCode::Uzs, "UZS"},
        {CurrencyCode::Ved, "VED"},
        {CurrencyCode::Vef, "VEF"},
        {CurrencyCode::Ves, "VES"},
        {CurrencyCode::Vnd, "VND"},
        {CurrencyCode::Vuv, "VUV"},
        {CurrencyCode::Wst, "WST"},
        {CurrencyCode::Xaf, "XAF"},
        {CurrencyCode::Xcd, "XCD"},
        {CurrencyCode::Xof, "XOF"},
        {CurrencyCode::Xpf, "XPF"},
        {CurrencyCode::Xxx, "XXX"},
        {CurrencyCode::Yer, "YER"},
        {CurrencyCode::Zar, "ZAR"},
        {CurrencyCode::Zmw, "ZMW"},
    });

    // A fixed price per unit adjustment to apply to the expanded item.
    struct ExpandedItemFixedPricePerUnitAdjustment {
        // The fixed price amount per quantity of the expanded item in presentment currency.
        double amount;
    };

    inline void to_json(Json & json, ExpandedItemFixedPricePerUnitAdjustment const & value) {
        json["amount"] = value.amount;
    }

    // A price adjustment to apply to a cart line.
    struct ExpandedItemPriceAdjustmentValue {
        // A fixed price per unit adjustment to apply to the expanded item.
        optional<ExpandedItemFixedPricePerUnitAdjustment> fixedPricePerUnit;
    };

    inline void to_json(Json & json, ExpandedItemPriceAdjustmentValue const & value) {
        json["fixedPricePerUnit"] = value.fixedPricePerUnit;
    }

    // Represents whether the current object has the given tag.
    struct HasTagResponse {
        // Whether the current object has the tag.
        bool hasTag;
        // The tag.
        std::string tag;
    };

    inline void from_json(Json const & json, HasTagResponse & value) {
        json.at("hasTag").get_to(value.hasTag);
        json.at("tag").get_to(value.tag);
    }

    // The image of an object.
    struct ImageInput {
        // The String of the image.
        std::string url;
    };

    inline void to_json(Json & json, ImageInput const & value) {
        json["url"] = value.url;
    }

    // ISO 639-1 language codes supported by Shopify.
    enum class LanguageCode {
        // Afrikaans.
        Af,
        // Akan.
        Ak,
        // Amharic.
        Am,
        // Arabic.
        Ar,
        // Assamese.
        As,
        // Azerbaijani.
        Az,
        // Belarusian.
        Be,
        // Bulgarian.
        Bg,
        // Bambara.
        Bm,
        // Bangla.
        Bn,
        // Tibetan.
        Bo,
        // Breton.
        Br,
        // Bosnian.
        Bs,
        // Catalan.
        Ca,
        // Chechen.
        Ce,
        // Czech.
        Cs,
        // Church Slavic.
        Cu,
        // Welsh.
        Cy,
        // Danish.
        Da,
        // German.
        De,
        // Dzongkha.
        Dz,
        // Ewe.
        Ee,
        // Greek.
        El,
        // English.
        En,
        // Esperanto.
        Eo,
        // Spanish.
        Es,
        // Estonian.
        Et,
        // Basque.
        Eu,
        // Persian.
        Fa,
        // Fulah.
        Ff,
        // Finnish.
        Fi,
        // Faroese.
        Fo,
        // French.
        Fr,
        // Western Frisian.
        Fy,
        // Irish.
        Ga,
        // Scottish Gaelic.
        Gd,
        // Galician.
        Gl,
        // Gujarati.
        Gu,
        // Manx.
        Gv,
        // Hausa.
        Ha,
        // Hebrew.
        He,
        // Hindi.
        Hi,
        // Croatian.
        Hr,
        // Hungarian.
        Hu,
        // Armenian.
        Hy,
        // Interlingua.
        Ia,
        // Indonesian.
        Id,
        // Igbo.
        Ig,
        // Sichuan Yi.
        Ii,
        // Icelandic.
        Is,
        // Italian.
        It,
        // Japanese.
        Ja,
        // Javanese.
        Jv,
        // Georgian.
        Ka,
        // Kikuyu.
        Ki,
        // Kazakh.
        Kk,
        // Kalaallisut.
        Kl,
        // Khmer.
        Km,
        // Kannada.
        Kn,
        // Korean.
        Ko,
        // Kashmiri.
        Ks,
        // Kurdish.
        Ku,
        // Cornish.
        Kw,
        // Kyrgyz.
        Ky,
        // Luxembourgish.
        Lb,
        // Ganda.
        Lg,
        // Lingala.
        Ln,
        // Lao.
        Lo,
        // Lithuanian.
        Lt,
        // Luba-Katanga.
        Lu,
        // Latvian.
        Lv,
        // Malagasy.
        Mg,
        // Māori.
        Mi,
        // Macedonian.
        Mk,
        // Malayalam.
        Ml,
        // Mongolian.
        Mn,
        // Marathi.
        Mr,
        // Malay.
        Ms,
        // Maltese.
        Mt,
        // Burmese.
        My,
        // Norwegian (Bokmål).
        Nb,
        // North Ndebele.
        Nd,
        // Nepali.
        Ne,
        // Dutch.
        Nl,
        // Norwegian Nynorsk.
        Nn,
        // Norwegian.
        No,
        // Oromo.
        Om,
        // Odia.
        Or,
        // Ossetic.
        Os,
        // Punjabi.
        Pa,
        // Polish.
        Pl,
        // Pashto.
        Ps,
        // Portuguese.
        Pt,
        // Portuguese (Brazil).
        PtBr,
        // Portuguese (Portugal).
        PtPt,
        // Quechua.
        Qu,
        // Romansh.
        Rm,
        // Rundi.
        Rn,
        // Romanian.
        Ro,
        // Russian.
        Ru,
        // Kinyarwanda.
        Rw,
        // Sindhi.
        Sd,
        // Northern Sami.
        Se,
        // Sango.
        Sg,
        // Sinhala.
        Si,
        // Slovak.
        Sk,
        // Slovenian.
        Sl,
        // Shona.
        Sn,
        // Somali.
        So,
        // Albanian.
        Sq,
        // Serbian.
        Sr,
        // Sundanese.
        Su,
        // Swedish.
        Sv,
        // Swahili.
        Sw,
        // Tamil.
        Ta,
        // Telugu.
        Te,
        // Tajik.
        Tg,
        // Thai.
        Th,
        // Tigrinya.
        Ti,
        // Turkmen.
        Tk,
        // Tongan.
        To,
        // Turkish.
        Tr,
        // Tatar.
        Tt,
        // Uyghur.
        Ug,
        // Ukrainian.
        Uk,
        // Urdu.
        Ur,
        // Uzbek.
        Uz,
        // Vietnamese.
        Vi,
        // Volapük.
        Vo,
        // Wolof.
        Wo,
        // Xhosa.
        Xh,
        // Yiddish.
        Yi,
        // Yoruba.
        Yo,
        // Chinese.
        Zh,
        // Chinese (Simplified).
        ZhCn,
        // Chinese (Traditional).
        ZhTw,
        // Zulu.
        Zu,
        Unknown = -1
    };

    NLOHMANN_JSON_SERIALIZE_ENUM(LanguageCode, {
        {LanguageCode::Unknown, nullptr},
        {LanguageCode::Af, "AF"},
        {LanguageCode::Ak, "AK"},
        {LanguageCode::Am, "AM"},
        {LanguageCode::Ar, "AR"},
        {LanguageCode::As, "AS"},
        {LanguageCode::Az, "AZ"},
        {LanguageCode::Be, "BE"},
        {LanguageCode::Bg, "BG"},
        {LanguageCode::Bm, "BM"},
        {LanguageCode::Bn, "BN"},
        {LanguageCode::Bo, "BO"},
        {LanguageCode::Br, "BR"},
        {LanguageCode::Bs, "BS"},
        {LanguageCode::Ca, "CA"},
        {LanguageCode::Ce, "CE"},
        {LanguageCode::Cs, "CS"},
        {LanguageCode::Cu, "CU"},
        {LanguageCode::Cy, "CY"},
        {LanguageCode::Da, "DA"},
        {LanguageCode::De, "DE"},
        {LanguageCode::Dz, "DZ"},
        {LanguageCode::Ee, "EE"},
        {LanguageCode::El, "EL"},
        {LanguageCode::En, "EN"},
        {LanguageCode::Eo, "EO"},
        {LanguageCode::Es, "ES"},
        {LanguageCode::Et, "ET"},
        {LanguageCode::Eu, "EU"},
        {LanguageCode::Fa, "FA"},
        {LanguageCode::Ff, "FF"},
        {LanguageCode::Fi, "FI"},
        {LanguageCode::Fo, "FO"},
        {LanguageCode::Fr, "FR"},
        {LanguageCode::Fy, "FY"},
        {LanguageCode::Ga, "GA"},
        {LanguageCode::Gd, "GD"},
        {LanguageCode::Gl, "GL"},
        {LanguageCode::Gu, "GU"},
        {LanguageCode::Gv, "GV"},
        {LanguageCode::Ha, "HA"},
        {LanguageCode::He, "HE"},
        {LanguageCode::Hi, "HI"},
        {LanguageCode::Hr, "HR"},
        {LanguageCode::Hu, "HU"},
        {LanguageCode::Hy, "HY"},
        {LanguageCode::Ia, "IA"},
        {LanguageCode::Id, "ID"},
        {LanguageCode::Ig, "IG"},
        {LanguageCode::Ii, "II"},
        {LanguageCode::Is, "IS"},
        {LanguageCode::It, "IT"},
        {LanguageCode::Ja, "JA"},
        {LanguageCode::Jv, "JV"},
        {LanguageCode::Ka, "KA"},
        {LanguageCode::Ki, "KI"},
        {LanguageCode::Kk, "KK"},
        {LanguageCode::Kl, "KL"},
        {LanguageCode::Km, "KM"},
        {LanguageCode::Kn, "KN"},
        {LanguageCode::Ko, "KO"},
        {LanguageCode::Ks, "KS"},
        {LanguageCode::Ku, "KU"},
        {LanguageCode::Kw, "KW"},
        {LanguageCode::Ky, "KY"},
        {LanguageCode::Lb, "LB"},
        {LanguageCode::Lg, "LG"},
        {LanguageCode::Ln, "LN"},
        {LanguageCode::Lo, "LO"},
        {LanguageCode::Lt, "LT"},
        {LanguageCode::Lu, "LU"},
        {LanguageCode::Lv, "LV"},
        {LanguageCode::Mg, "MG"},
        {LanguageCode::Mi, "MI"},
        {LanguageCode::Mk, "MK"},
        {LanguageCode::Ml, "ML"},
        {LanguageCode::Mn, "MN"},
        {LanguageCode::Mr, "MR"},
        {LanguageCode::Ms, "MS"},
        {LanguageCode::Mt, "MT"},
        {LanguageCode::My, "MY"},
        {LanguageCode::Nb, "NB"},
        {LanguageCode::Nd, "ND"},
        {LanguageCode::Ne, "NE"},
        {LanguageCode::Nl, "NL"},
        {LanguageCode::Nn, "NN"},
        {LanguageCode::No, "NO"},
        {LanguageCode::Om, "OM"},
        {LanguageCode::Or, "OR"},
        {LanguageCode::Os, "OS"},
        {LanguageCode::Pa, "PA"},
        {LanguageCode::Pl, "PL"},
        {LanguageCode::Ps, "PS"},
        {LanguageCode::Pt, "PT"},
        {LanguageCode::PtBr, "PT_BR"},
        {LanguageCode::PtPt, "PT_PT"},
        {LanguageCode::Qu, "QU"},
        {LanguageCode::Rm, "RM"},
        {LanguageCode::Rn, "RN"},
        {LanguageCode::Ro, "RO"},
        {LanguageCode::Ru, "RU"},
        {LanguageCode::Rw, "RW"},
        {LanguageCode::Sd, "SD"},
        {LanguageCode::Se, "SE"},
        {LanguageCode::Sg, "SG"},
        {LanguageCode::Si, "SI"},
        {LanguageCode::Sk, "SK"},
        {LanguageCode::Sl, "SL"},
        {LanguageCode::Sn, "SN"},
        {LanguageCode::So, "SO"},
        {LanguageCode::Sq, "SQ"},
        {LanguageCode::Sr, "SR"},
        {LanguageCode::Su, "SU"},
        {LanguageCode::Sv, "SV"},
        {LanguageCode::Sw, "SW"},
        {LanguageCode::Ta, "TA"},
        {LanguageCode::Te, "TE"},
        {LanguageCode::Tg, "TG"},
        {LanguageCode::Th, "TH"},
        {LanguageCode::Ti, "TI"},
        {LanguageCode::Tk, "TK"},
        {LanguageCode::To, "TO"},
        {LanguageCode::Tr, "TR"},
        {LanguageCode::Tt, "TT"},
        {LanguageCode::Ug, "UG"},
        {LanguageCode::Uk, "UK"},
        {LanguageCode::Ur, "UR"},
        {LanguageCode::Uz, "UZ"},
        {LanguageCode::Vi, "VI"},
        {LanguageCode::Vo, "VO"},
        {LanguageCode::Wo, "WO"},
        {LanguageCode::Xh, "XH"},
        {LanguageCode::Yi, "YI"},
        {LanguageCode::Yo, "YO"},
        {LanguageCode::Zh, "ZH"},
        {LanguageCode::ZhCn, "ZH_CN"},
        {LanguageCode::ZhTw, "ZH_TW"},
        {LanguageCode::Zu, "ZU"},
    });

    // Represents limited information about the current time relative to the parent object.
    struct LocalTime {
        // The current date relative to the parent object.
        std::string date;
        // Returns true if the current date and time is at or past the given date and time, and false otherwise.
        bool StringAfter;
        // Returns true if the current date and time is before the given date and time, and false otherwise.
        bool StringBefore;
        // Returns true if the current date and time is between the two given date and times, and false otherwise.
        bool StringBetween;
        // Returns true if the current time is at or past the given time, and false otherwise.
        bool timeAfter;
        // Returns true if the current time is at or past the given time, and false otherwise.
        bool timeBefore;
        // Returns true if the current time is between the two given times, and false otherwise.
        bool timeBetween;
    };

    inline void from_json(Json const & json, LocalTime & value) {
        json.at("date").get_to(value.date);
        json.at("StringAfter").get_to(value.StringAfter);
        json.at("StringBefore").get_to(value.StringBefore);
        json.at("StringBetween").get_to(value.StringBetween);
        json.at("timeAfter").get_to(value.timeAfter);
        json.at("timeBefore").get_to(value.timeBefore);
        json.at("timeBetween").get_to(value.timeBetween);
    }

    // A country which comprises a market.
    struct MarketRegionCountry {
        // The two-letter code for the country.
        CountryCode code;
        // The country name in the language of the current localization.
        std::string name;
    };

    inline void from_json(Json const & json, MarketRegionCountry & value) {
        json.at("code").get_to(value.code);
        json.at("name").get_to(value.name);
    }

    /*
    [Metafields](https://shopify.dev/apps/metafields)
    enable you to attach additional information to a
    Shopify resource, such as a [Product](https://shopify.dev/api/admin-graphql/latest/objects/product)
    or a [Collection](https://shopify.dev/api/admin-graphql/latest/objects/collection).
    For more information about the Shopify resources that you can attach metafields to, refer to
    [HasMetafields](https://shopify.dev/api/admin/graphql/reference/common-objects/HasMetafields).
    */
    struct Metafield {
        // The data stored in the metafield in String format.
        std::string jsonValue;
        /*
        The type of data that the metafield stores in the `value` field.
        Refer to the list of [supported types](https://shopify.dev/apps/metafields/types).
        */
        std::string type;
        // The data stored in the metafield. Always stored as a string, regardless of the metafield's type.
        std::string value;
    };

    inline void from_json(Json const & json, Metafield & value) {
        json.at("jsonValue").get_to(value.jsonValue);
        json.at("type").get_to(value.type);
        json.at("value").get_to(value.value);
    }

    // A monetary value with currency.
    struct MoneyV2 {
        // Float money amount.
        double amount;
        // Currency of the money.
        CurrencyCode currencyCode;
    };

    inline void from_json(Json const & json, MoneyV2 & value) {
        json.at("amount").get_to(value.amount);
        json.at("currencyCode").get_to(value.currencyCode);
    }

    struct PriceAdjustmentValue {
        // The value of the price adjustment.
        double value;
    };

    inline void to_json(Json & json, PriceAdjustmentValue const & value) {
        json["value"] = value.value;
    }

    // Represents a product.
    struct Product {
        // A unique human-friendly string of the product's title.
        std::string handle;
        // Whether the product has any of the given tags.
        bool hasAnyTag;
        // Whether the product has the given tags.
        std::vector<HasTagResponse> hasTags;
        // A globally-unique identifier.
        Id id;
        // Whether the product is in any of the given collections.
        bool inAnyCollection;
        // Whether the product is in the given collections.
        std::vector<CollectionMembership> inCollections;
        // Whether the product is a gift card.
        bool isGiftCard;
        // Returns a metafield by namespace and key that belongs to the resource.
        optional<Metafield> metafield;
        // The product type specified by the merchant.
        optional<std::string> productType;
        // The localized title of the product in the customer’s locale.
        std::string title;
        // The name of the product's vendor.
        optional<std::string> vendor;
    };

    inline void from_json(Json const & json, Product & value) {
        json.at("handle").get_to(value.handle);
        json.at("hasAnyTag").get_to(value.hasAnyTag);
        json.at("hasTags").get_to(value.hasTags);
        json.at("id").get_to(value.id);
        json.at("inAnyCollection").get_to(value.inAnyCollection);
        json.at("inCollections").get_to(value.inCollections);
        json.at("isGiftCard").get_to(value.isGiftCard);
        {
            auto it = json.find("metafield");
            if (it != json.end()) {
                it->get_to(value.metafield);
            } else {
                value.metafield.reset();
            }
        }
        {
            auto it = json.find("productType");
            if (it != json.end()) {
                it->get_to(value.productType);
            } else {
                value.productType.reset();
            }
        }
        json.at("title").get_to(value.title);
        {
            auto it = json.find("vendor");
            if (it != json.end()) {
                it->get_to(value.vendor);
            } else {
                value.vendor.reset();
            }
        }
    }

    // Represents how products and variants can be sold and purchased.
    struct SellingPlan {
        // The description of the selling plan.
        optional<std::string> description;
        // A globally-unique identifier.
        Id id;
        // Returns a metafield by namespace and key that belongs to the resource.
        optional<Metafield> metafield;
        // The name of the selling plan. For example, '6 weeks of prepaid granola, delivered weekly'.
        std::string name;
        // Whether purchasing the selling plan will result in multiple deliveries.
        bool recurringDeliveries;
    };

    inline void from_json(Json const & json, SellingPlan & value) {
        {
            auto it = json.find("description");
            if (it != json.end()) {
                it->get_to(value.description);
            } else {
                value.description.reset();
            }
        }
        json.at("id").get_to(value.id);
        {
            auto it = json.find("metafield");
            if (it != json.end()) {
                it->get_to(value.metafield);
            } else {
                value.metafield.reset();
            }
        }
        json.at("name").get_to(value.name);
        json.at("recurringDeliveries").get_to(value.recurringDeliveries);
    }

    // The resulting prices for variants when they're purchased with a specific selling plan.
    struct SellingPlanAllocationPriceAdjustment {
        /*
        The effective price for a single delivery. For example, for a prepaid
        subscription plan that includes 6 deliveries at the price of $48.00, the per
        delivery price is $8.00.
        */
        MoneyV2 perDeliveryPrice;
        /*
        The price of the variant when it's purchased with a selling plan For example,
        for a prepaid subscription plan that includes 6 deliveries of $10.00 granola,
        where the customer gets 20% off, the price is 6 x $10.00 x 0.80 = $48.00.
        */
        MoneyV2 price;
    };

    inline void from_json(Json const & json, SellingPlanAllocationPriceAdjustment & value) {
        json.at("perDeliveryPrice").get_to(value.perDeliveryPrice);
        json.at("price").get_to(value.price);
    }

    // Information about the shop.
    struct Shop {
        // Information about the current time relative to the shop's timezone setting.
        LocalTime localTime;
        // Returns a metafield by namespace and key that belongs to the resource.
        optional<Metafield> metafield;
    };

    inline void from_json(Json const & json, Shop & value) {
        json.at("localTime").get_to(value.localTime);
        {
            auto it = json.find("metafield");
            if (it != json.end()) {
                it->get_to(value.metafield);
            } else {
                value.metafield.reset();
            }
        }
    }

    // A fixed price per unit adjustment to apply to a cart line.
    struct UpdateOperationFixedPricePerUnitAdjustment {
        // The fixed price amount per quantity of the cart line item in presentment currency.
        double amount;
    };

    inline void to_json(Json & json, UpdateOperationFixedPricePerUnitAdjustment const & value) {
        json["amount"] = value.amount;
    }

    // A price adjustment to apply to a cart line item.
    struct UpdateOperationPriceAdjustmentValue {
        // A fixed price per unit adjustment to apply to a cart line.
        optional<UpdateOperationFixedPricePerUnitAdjustment> fixedPricePerUnit;
    };

    inline void to_json(Json & json, UpdateOperationPriceAdjustmentValue const & value) {
        json["fixedPricePerUnit"] = value.fixedPricePerUnit;
    }

    // Units of measurement for weight.
    enum class WeightUnit {
        // Metric system unit of mass.
        Grams,
        // 1 kilogram equals 1000 grams.
        Kilograms,
        // Imperial system unit of mass.
        Ounces,
        // 1 pound equals 16 ounces.
        Pounds,
        Unknown = -1
    };

    NLOHMANN_JSON_SERIALIZE_ENUM(WeightUnit, {
        {WeightUnit::Unknown, nullptr},
        {WeightUnit::Grams, "GRAMS"},
        {WeightUnit::Kilograms, "KILOGRAMS"},
        {WeightUnit::Ounces, "OUNCES"},
        {WeightUnit::Pounds, "POUNDS"},
    });

    // The cost of the merchandise line that the buyer will pay at checkout.
    struct CartLineCost {
        // The amount of the merchandise line.
        MoneyV2 amountPerQuantity;
        // The compare at amount of the merchandise line.
        optional<MoneyV2> compareAtAmountPerQuantity;
        // The cost of the merchandise line before line-level discounts.
        MoneyV2 subtotalAmount;
        // The total cost of the merchandise line.
        MoneyV2 totalAmount;
    };

    inline void from_json(Json const & json, CartLineCost & value) {
        json.at("amountPerQuantity").get_to(value.amountPerQuantity);
        {
            auto it = json.find("compareAtAmountPerQuantity");
            if (it != json.end()) {
                it->get_to(value.compareAtAmountPerQuantity);
            } else {
                value.compareAtAmountPerQuantity.reset();
            }
        }
        json.at("subtotalAmount").get_to(value.subtotalAmount);
        json.at("totalAmount").get_to(value.totalAmount);
    }

    // A customization which applies cart transformations to the merchandise lines.
    struct CartTransform {
        // Returns a metafield by namespace and key that belongs to the resource.
        optional<Metafield> metafield;
    };

    inline void from_json(Json const & json, CartTransform & value) {
        {
            auto it = json.find("metafield");
            if (it != json.end()) {
                it->get_to(value.metafield);
            } else {
                value.metafield.reset();
            }
        }
    }

    // Represents information about a company which is also a customer of the shop.
    struct Company {
        // The date and time ([ISO 8601 format](http://en.wikipedia.org/wiki/ISO_8601)) at which the company was created in Shopify.
        std::string createdAt;
        // A unique externally-supplied ID for the company.
        optional<std::string> externalId;
        // The ID of the company.
        Id id;
        // Returns a metafield by namespace and key that belongs to the resource.
        optional<Metafield> metafield;
        // The name of the company.
        std::string name;
        // The date and time ([ISO 8601 format](http://en.wikipedia.org/wiki/ISO_8601)) at which the company was last modified.
        std::string updatedAt;
    };

    inline void from_json(Json const & json, Company & value) {
        json.at("createdAt").get_to(value.createdAt);
        {
            auto it = json.find("externalId");
            if (it != json.end()) {
                it->get_to(value.externalId);
            } else {
                value.externalId.reset();
            }
        }
        json.at("id").get_to(value.id);
        {
            auto it = json.find("metafield");
            if (it != json.end()) {
                it->get_to(value.metafield);
            } else {
                value.metafield.reset();
            }
        }
        json.at("name").get_to(value.name);
        json.at("updatedAt").get_to(value.updatedAt);
    }

    // A company's location.
    struct CompanyLocation {
        /*
        The date and time ([ISO 8601 format](http://en.wikipedia.org/wiki/ISO_8601))
        at which the company location was created in Shopify.
        */
        std::string createdAt;
        // A unique externally-supplied ID for the company.
        optional<std::string> externalId;
        // The ID of the company.
        Id id;
        // The preferred locale of the company location.
        optional<std::string> locale;
        // Returns a metafield by namespace and key that belongs to the resource.
        optional<Metafield> metafield;
        // The name of the company location.
        std::string name;
        /*
        The date and time ([ISO 8601 format](http://en.wikipedia.org/wiki/ISO_8601))
        at which the company location was last modified.
        */
        std::string updatedAt;
    };

    inline void from_json(Json const & json, CompanyLocation & value) {
        json.at("createdAt").get_to(value.createdAt);
        {
            auto it = json.find("externalId");
            if (it != json.end()) {
                it->get_to(value.externalId);
            } else {
                value.externalId.reset();
            }
        }
        json.at("id").get_to(value.id);
        {
            auto it = json.find("locale");
            if (it != json.end()) {
                it->get_to(value.locale);
            } else {
                value.locale.reset();
            }
        }
        {
            auto it = json.find("metafield");
            if (it != json.end()) {
                it->get_to(value.metafield);
            } else {
                value.metafield.reset();
            }
        }
        json.at("name").get_to(value.name);
        json.at("updatedAt").get_to(value.updatedAt);
    }

    // A country.
    struct Country {
        // The ISO code of the country.
        CountryCode isoCode;
    };

    inline void from_json(Json const & json, Country & value) {
        json.at("isoCode").get_to(value.isoCode);
    }

    // A custom product.
    struct CustomProduct {
        // Whether the merchandise is a gift card.
        bool isGiftCard;
        // Whether the merchandise requires shipping.
        bool requiresShipping;
        // The localized title of the product in the customer’s locale.
        std::string title;
        // The weight of the product variant in the unit system specified with `weight_unit`.
        optional<double> weight;
        // Unit of measurement for weight.
        WeightUnit weightUnit;
    };

    inline void from_json(Json const & json, CustomProduct & value) {
        json.at("isGiftCard").get_to(value.isGiftCard);
        json.at("requiresShipping").get_to(value.requiresShipping);
        json.at("title").get_to(value.title);
        {
            auto it = json.find("weight");
            if (it != json.end()) {
                it->get_to(value.weight);
            } else {
                value.weight.reset();
            }
        }
        json.at("weightUnit").get_to(value.weightUnit);
    }

    // Represents a customer with the shop.
    struct Customer {
        /*
        The total amount of money spent by the customer. Converted from the shop's
        currency to the currency of the cart using a market rate.
        */
        MoneyV2 amountSpent;
        // The customer’s name, email or phone number.
        std::string displayName;
        // The customer’s email address.
        optional<std::string> email;
        // The customer's first name.
        optional<std::string> firstName;
        // Whether the customer has any of the given tags.
        bool hasAnyTag;
        // Whether the customer has the given tags.
        std::vector<HasTagResponse> hasTags;
        // A unique identifier for the customer.
        Id id;
        // The customer's last name.
        optional<std::string> lastName;
        // Returns a metafield by namespace and key that belongs to the resource.
        optional<Metafield> metafield;
        // The number of orders made by the customer.
        int32_t numberOfOrders;
    };

    inline void from_json(Json const & json, Customer & value) {
        json.at("amountSpent").get_to(value.amountSpent);
        json.at("displayName").get_to(value.displayName);
        {
            auto it = json.find("email");
            if (it != json.end()) {
                it->get_to(value.email);
            } else {
                value.email.reset();
            }
        }
        {
            auto it = json.find("firstName");
            if (it != json.end()) {
                it->get_to(value.firstName);
            } else {
                value.firstName.reset();
            }
        }
        json.at("hasAnyTag").get_to(value.hasAnyTag);
        json.at("hasTags").get_to(value.hasTags);
        json.at("id").get_to(value.id);
        {
            auto it = json.find("lastName");
            if (it != json.end()) {
                it->get_to(value.lastName);
            } else {
                value.lastName.reset();
            }
        }
        {
            auto it = json.find("metafield");
            if (it != json.end()) {
                it->get_to(value.metafield);
            } else {
                value.metafield.reset();
            }
        }
        json.at("numberOfOrders").get_to(value.numberOfOrders);
    }

    // A price adjustment to apply to the expanded item.
    struct ExpandedItemPriceAdjustment {
        // The price adjustment for the expanded item.
        ExpandedItemPriceAdjustmentValue adjustment;
    };

    inline void to_json(Json & json, ExpandedItemPriceAdjustment const & value) {
        json["adjustment"] = value.adjustment;
    }

    // A language.
    struct Language {
        // The ISO code.
        LanguageCode isoCode;
    };

    inline void from_json(Json const & json, Language & value) {
        json.at("isoCode").get_to(value.isoCode);
    }

    struct UnknownMarketRegion {
        optional<std::string> name;
    };

    // Represents a region.
    struct MarketRegion {
        variant<MarketRegionCountry, UnknownMarketRegion> implementation;

        // The name of the region in the language of the current localization.
        optional<std::string> const & name() const {
            return visit([](auto const & implementation) -> optional<std::string> const & {
                return implementation.name;
            }, implementation);
        }

    };

    inline void from_json(Json const & json, UnknownMarketRegion & value) {
        {
            auto it = json.find("name");
            if (it != json.end()) {
                it->get_to(value.name);
            } else {
                value.name.reset();
            }
        }
    }

    inline void from_json(Json const & json, MarketRegion & value) {
        std::string occupiedType = json.at("__typename");
        if (occupiedType == "MarketRegionCountry") {
            value = {MarketRegionCountry(json)};
        } else {
            value = {UnknownMarketRegion(json)};
        }
    }

    struct PriceAdjustment {
        // The percentage price decrease of the price adjustment.
        optional<PriceAdjustmentValue> percentageDecrease;
    };

    inline void to_json(Json & json, PriceAdjustment const & value) {
        json["percentageDecrease"] = value.percentageDecrease;
    }

    // Represents a product variant.
    struct ProductVariant {
        // A globally-unique identifier.
        Id id;
        // Returns a metafield by namespace and key that belongs to the resource.
        optional<Metafield> metafield;
        // The product that this variant belongs to.
        Product product;
        // Whether the merchandise requires shipping.
        bool requiresShipping;
        // An identifier for the product variant in the shop. Required in order to connect to a fulfillment service.
        optional<std::string> sku;
        // The localized title of the product variant in the customer’s locale.
        optional<std::string> title;
        // The weight of the product variant in the unit system specified with `weight_unit`.
        optional<double> weight;
        // Unit of measurement for weight.
        WeightUnit weightUnit;
    };

    inline void from_json(Json const & json, ProductVariant & value) {
        json.at("id").get_to(value.id);
        {
            auto it = json.find("metafield");
            if (it != json.end()) {
                it->get_to(value.metafield);
            } else {
                value.metafield.reset();
            }
        }
        json.at("product").get_to(value.product);
        json.at("requiresShipping").get_to(value.requiresShipping);
        {
            auto it = json.find("sku");
            if (it != json.end()) {
                it->get_to(value.sku);
            } else {
                value.sku.reset();
            }
        }
        {
            auto it = json.find("title");
            if (it != json.end()) {
                it->get_to(value.title);
            } else {
                value.title.reset();
            }
        }
        {
            auto it = json.find("weight");
            if (it != json.end()) {
                it->get_to(value.weight);
            } else {
                value.weight.reset();
            }
        }
        json.at("weightUnit").get_to(value.weightUnit);
    }

    // Represents information about the buyer that is interacting with the cart.
    struct PurchasingCompany {
        // The company associated to the order or draft order.
        Company company;
        // The company contact associated to the order or draft order.
        optional<CompanyContact> contact;
        // The company location associated to the order or draft order.
        CompanyLocation location;
    };

    inline void from_json(Json const & json, PurchasingCompany & value) {
        json.at("company").get_to(value.company);
        {
            auto it = json.find("contact");
            if (it != json.end()) {
                it->get_to(value.contact);
            } else {
                value.contact.reset();
            }
        }
        json.at("location").get_to(value.location);
    }

    /*
    Represents an association between a variant and a selling plan. Selling plan
    allocations describe the options offered for each variant, and the price of the
    variant when purchased with a selling plan.
    */
    struct SellingPlanAllocation {
        /*
        A list of price adjustments, with a maximum of two. When there are two, the
        first price adjustment goes into effect at the time of purchase, while the
        second one starts after a certain number of orders. A price adjustment
        represents how a selling plan affects pricing when a variant is purchased with
        a selling plan. Prices display in the customer's currency if the shop is
        configured for it.
        */
        std::vector<SellingPlanAllocationPriceAdjustment> priceAdjustments;
        /*
        A representation of how products and variants can be sold and purchased. For
        example, an individual selling plan could be '6 weeks of prepaid granola,
        delivered weekly'.
        */
        SellingPlan sellingPlan;
    };

    inline void from_json(Json const & json, SellingPlanAllocation & value) {
        json.at("priceAdjustments").get_to(value.priceAdjustments);
        json.at("sellingPlan").get_to(value.sellingPlan);
    }

    // A price adjustment to apply to a cart line item.
    struct UpdateOperationPriceAdjustment {
        // The price adjustment per unit to apply to the cart line item.
        UpdateOperationPriceAdjustmentValue adjustment;
    };

    inline void to_json(Json & json, UpdateOperationPriceAdjustment const & value) {
        json["adjustment"] = value.adjustment;
    }

    // Represents information about the buyer that is interacting with the cart.
    struct BuyerIdentity {
        // The customer associated with the cart.
        optional<Customer> customer;
        // The email address of the buyer that's interacting with the cart.
        optional<std::string> email;
        // Whether the buyer authenticated with a customer account.
        bool isAuthenticated;
        // The phone number of the buyer that's interacting with the cart.
        optional<std::string> phone;
        // The purchasing company associated with the cart.
        optional<PurchasingCompany> purchasingCompany;
    };

    inline void from_json(Json const & json, BuyerIdentity & value) {
        {
            auto it = json.find("customer");
            if (it != json.end()) {
                it->get_to(value.customer);
            } else {
                value.customer.reset();
            }
        }
        {
            auto it = json.find("email");
            if (it != json.end()) {
                it->get_to(value.email);
            } else {
                value.email.reset();
            }
        }
        json.at("isAuthenticated").get_to(value.isAuthenticated);
        {
            auto it = json.find("phone");
            if (it != json.end()) {
                it->get_to(value.phone);
            } else {
                value.phone.reset();
            }
        }
        {
            auto it = json.find("purchasingCompany");
            if (it != json.end()) {
                it->get_to(value.purchasingCompany);
            } else {
                value.purchasingCompany.reset();
            }
        }
    }

    struct ExpandedItem {
        // The CartLine attributes to be added to component line.
        optional<std::vector<AttributeOutput>> attributes;
        // The merchandise id of the expanded item.
        Id merchandiseId;
        // The price adjustment for the expanded item.
        optional<ExpandedItemPriceAdjustment> price;
        // The quantity of the expanded item.The max quantity is 2000.
        int32_t quantity;
    };

    inline void to_json(Json & json, ExpandedItem const & value) {
        json["attributes"] = value.attributes;
        json["merchandiseId"] = value.merchandiseId;
        json["price"] = value.price;
        json["quantity"] = value.quantity;
    }

    /*
    A market is a group of one or more regions that you want to target for international sales.
    By creating a market, you can configure a distinct, localized shopping experience for
    customers from a specific area of the world. For example, you can
    [change currency](https://shopify.dev/api/admin-graphql/current/mutations/marketCurrencySettingsUpdate),
    [configure international pricing](https://shopify.dev/api/examples/product-price-lists),
    or [add market-specific domains or subfolders](https://shopify.dev/api/admin-graphql/current/objects/MarketWebPresence).
    */
    struct Market {
        // A human-readable unique string for the market automatically generated from its title.
        std::string handle;
        // A globally-unique identifier.
        Id id;
        // Returns a metafield by namespace and key that belongs to the resource.
        optional<Metafield> metafield;
        // A geographic region which comprises a market.
        std::vector<MarketRegion> regions;
    };

    inline void from_json(Json const & json, Market & value) {
        json.at("handle").get_to(value.handle);
        json.at("id").get_to(value.id);
        {
            auto it = json.find("metafield");
            if (it != json.end()) {
                it->get_to(value.metafield);
            } else {
                value.metafield.reset();
            }
        }
        json.at("regions").get_to(value.regions);
    }

    using UnknownMerchandise = monostate;
    // The merchandise to be purchased at checkout.
    using Merchandise = variant<CustomProduct, ProductVariant, UnknownMerchandise>;

    inline void from_json(Json const & json, Merchandise & value) {
        std::string occupiedType = json.at("__typename");
        if (occupiedType == "CustomProduct") {
            value = {CustomProduct(json)};
        } else if (occupiedType == "ProductVariant") {
            value = {ProductVariant(json)};
        } else {
            value = {UnknownMerchandise()};
        }
    }

    // A cart line merge operation.
    struct MergeOperation {
        // The CartLine attributes to be added to the parent line.
        optional<std::vector<AttributeOutput>> attributes;
        // The list of cart lines to merge.
        std::vector<CartLineInput> cartLines;
        // The image of the group.
        optional<ImageInput> image;
        // The product variant that models the group of lines.
        Id parentVariantId;
        // The price adjustment to the group.
        optional<PriceAdjustment> price;
        // The name of the group of lines to merge. If it isn't specified, it will use the parent_variant' name.
        optional<std::string> title;
    };

    inline void to_json(Json & json, MergeOperation const & value) {
        json["attributes"] = value.attributes;
        json["cartLines"] = value.cartLines;
        json["image"] = value.image;
        json["parentVariantId"] = value.parentVariantId;
        json["price"] = value.price;
        json["title"] = value.title;
    }

    // A cart line update operation. Only stores on the Shopify Plus plan can use apps with update operations.
    struct UpdateOperation {
        // The ID of the cart line.
        Id cartLineId;
        // The image override for the cart line item.
        optional<ImageInput> image;
        // The price adjustment for the cart line item.
        optional<UpdateOperationPriceAdjustment> price;
        // The title override for the cart line item. If not provided, the variant title is used.
        optional<std::string> title;
    };

    inline void to_json(Json & json, UpdateOperation const & value) {
        json["cartLineId"] = value.cartLineId;
        json["image"] = value.image;
        json["price"] = value.price;
        json["title"] = value.title;
    }

    // Represents information about the merchandise in the cart.
    struct CartLine {
        /*
        Retrieve a cart line attribute by key.
        
        Cart line attributes are also known as line item properties in Liquid.
        */
        optional<Attribute> attribute;
        // The cost of the merchandise line that the buyer will pay at checkout.
        CartLineCost cost;
        // The ID of the cart line.
        Id id;
        // The merchandise that the buyer intends to purchase.
        Merchandise merchandise;
        // The quantity of the merchandise that the customer intends to purchase.
        int32_t quantity;
        /*
        The selling plan associated with the cart line and the effect that each
        selling plan has on variants when they're purchased.
        */
        optional<SellingPlanAllocation> sellingPlanAllocation;
    };

    inline void from_json(Json const & json, CartLine & value) {
        {
            auto it = json.find("attribute");
            if (it != json.end()) {
                it->get_to(value.attribute);
            } else {
                value.attribute.reset();
            }
        }
        json.at("cost").get_to(value.cost);
        json.at("id").get_to(value.id);
        json.at("merchandise").get_to(value.merchandise);
        json.at("quantity").get_to(value.quantity);
        {
            auto it = json.find("sellingPlanAllocation");
            if (it != json.end()) {
                it->get_to(value.sellingPlanAllocation);
            } else {
                value.sellingPlanAllocation.reset();
            }
        }
    }

    // A cart line expand operation.
    struct ExpandOperation {
        // The cart line id to expand.
        Id cartLineId;
        // The cart items to expand.
        std::vector<ExpandedItem> expandedCartItems;
        // The image of the group.
        optional<ImageInput> image;
        // The price adjustment to the group.
        optional<PriceAdjustment> price;
        // Title override. If title is not provided, variant title is used.
        optional<std::string> title;
    };

    inline void to_json(Json & json, ExpandOperation const & value) {
        json["cartLineId"] = value.cartLineId;
        json["expandedCartItems"] = value.expandedCartItems;
        json["image"] = value.image;
        json["price"] = value.price;
        json["title"] = value.title;
    }

    struct UnknownHasMetafields {
        optional<Metafield> metafield;
    };

    // Represents information about the metafields associated to the specified resource.
    struct HasMetafields {
        variant<CartTransform, Company, CompanyLocation, Customer, Market, Product, ProductVariant, SellingPlan, Shop, UnknownHasMetafields> implementation;

        // Returns a metafield by namespace and key that belongs to the resource.
        optional<Metafield> const & metafield() const {
            return visit([](auto const & implementation) -> optional<Metafield> const & {
                return implementation.metafield;
            }, implementation);
        }

    };

    inline void from_json(Json const & json, UnknownHasMetafields & value) {
        {
            auto it = json.find("metafield");
            if (it != json.end()) {
                it->get_to(value.metafield);
            } else {
                value.metafield.reset();
            }
        }
    }

    inline void from_json(Json const & json, HasMetafields & value) {
        std::string occupiedType = json.at("__typename");
        if (occupiedType == "CartTransform") {
            value = {CartTransform(json)};
        } else if (occupiedType == "Company") {
            value = {Company(json)};
        } else if (occupiedType == "CompanyLocation") {
            value = {CompanyLocation(json)};
        } else if (occupiedType == "Customer") {
            value = {Customer(json)};
        } else if (occupiedType == "Market") {
            value = {Market(json)};
        } else if (occupiedType == "Product") {
            value = {Product(json)};
        } else if (occupiedType == "ProductVariant") {
            value = {ProductVariant(json)};
        } else if (occupiedType == "SellingPlan") {
            value = {SellingPlan(json)};
        } else if (occupiedType == "Shop") {
            value = {Shop(json)};
        } else {
            value = {UnknownHasMetafields(json)};
        }
    }

    // Information about the localized experiences configured for the shop.
    struct Localization {
        // The country of the active localized experience.
        Country country;
        // The language of the active localized experience.
        Language language;
        // The market of the active localized experience.
        Market market;
    };

    inline void from_json(Json const & json, Localization & value) {
        json.at("country").get_to(value.country);
        json.at("language").get_to(value.language);
        json.at("market").get_to(value.market);
    }

    // A cart represents the merchandise that a buyer intends to purchase, and the cost associated with the cart.
    struct Cart {
        // The attributes associated with the cart. Attributes are represented as key-value pairs.
        optional<Attribute> attribute;
        // Information about the buyer that is interacting with the cart.
        optional<BuyerIdentity> buyerIdentity;
        // A list of lines containing information about the items the customer intends to purchase.
        std::vector<CartLine> lines;
    };

    inline void from_json(Json const & json, Cart & value) {
        {
            auto it = json.find("attribute");
            if (it != json.end()) {
                it->get_to(value.attribute);
            } else {
                value.attribute.reset();
            }
        }
        {
            auto it = json.find("buyerIdentity");
            if (it != json.end()) {
                it->get_to(value.buyerIdentity);
            } else {
                value.buyerIdentity.reset();
            }
        }
        json.at("lines").get_to(value.lines);
    }

    // An operation to apply to the Cart.
    struct CartOperation {
        // A cart line expand operation.
        optional<ExpandOperation> expand;
        // A cart line merge operation.
        optional<MergeOperation> merge;
        // A cart line update operation. Only stores on the Shopify Plus plan can use apps with update operations.
        optional<UpdateOperation> update;
    };

    inline void to_json(Json & json, CartOperation const & value) {
        json["expand"] = value.expand;
        json["merge"] = value.merge;
        json["update"] = value.update;
    }

    // The run target result. In API versions 2023-10 and beyond, this type is deprecated in favor of `FunctionRunResult`.
    struct FunctionResult {
        // Cart operations to run on Cart.
        std::vector<CartOperation> operations;
    };

    inline void to_json(Json & json, FunctionResult const & value) {
        json["operations"] = value.operations;
    }

    // The run target result.
    struct FunctionRunResult {
        // Cart operations to run on Cart.
        std::vector<CartOperation> operations;
    };

    inline void to_json(Json & json, FunctionRunResult const & value) {
        json["operations"] = value.operations;
    }

    namespace Input {

        // The cart.
        struct CartField {

            static Operation constexpr operation = Operation::Query;

            static Json request(optional<std::string> const & cartAttributeKey, std::vector<std::string> const & cartBuyerIdentityBuyerIdentityCustomerCustomerHasAnyTagTags, std::vector<std::string> const & cartBuyerIdentityBuyerIdentityCustomerCustomerHasTagsTags, std::string const & cartBuyerIdentityBuyerIdentityCustomerCustomerMetafieldKey, optional<std::string> const & cartBuyerIdentityBuyerIdentityCustomerCustomerMetafieldNamespace, std::string const & cartBuyerIdentityBuyerIdentityPurchasingCompanyPurchasingCompanyCompanyCompanyMetafieldKey, optional<std::string> const & cartBuyerIdentityBuyerIdentityPurchasingCompanyPurchasingCompanyCompanyCompanyMetafieldNamespace, std::string const & cartBuyerIdentityBuyerIdentityPurchasingCompanyPurchasingCompanyLocationCompanyLocationMetafieldKey, optional<std::string> const & cartBuyerIdentityBuyerIdentityPurchasingCompanyPurchasingCompanyLocationCompanyLocationMetafieldNamespace, optional<std::string> const & cartLinesCartLineAttributeKey, std::string const & cartLinesCartLineMerchandiseMerchandiseProductVariantMetafieldKey, optional<std::string> const & cartLinesCartLineMerchandiseMerchandiseProductVariantMetafieldNamespace, std::vector<std::string> const & cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductHasAnyTagTags, std::vector<std::string> const & cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductHasTagsTags, std::vector<Id> const & cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductInAnyCollectionIds, std::vector<Id> const & cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductInCollectionsIds, std::string const & cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductMetafieldKey, optional<std::string> const & cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductMetafieldNamespace, std::string const & cartLinesCartLineSellingPlanAllocationSellingPlanAllocationSellingPlanSellingPlanMetafieldKey, optional<std::string> const & cartLinesCartLineSellingPlanAllocationSellingPlanAllocationSellingPlanSellingPlanMetafieldNamespace) {
                Json query = R"(
                    query Cart(
                        $cartAttributeKey: String
                        $cartBuyerIdentityBuyerIdentityCustomerCustomerHasAnyTagTags: [String!]!
                        $cartBuyerIdentityBuyerIdentityCustomerCustomerHasTagsTags: [String!]!
                        $cartBuyerIdentityBuyerIdentityCustomerCustomerMetafieldKey: String!
                        $cartBuyerIdentityBuyerIdentityCustomerCustomerMetafieldNamespace: String
                        $cartBuyerIdentityBuyerIdentityPurchasingCompanyPurchasingCompanyCompanyCompanyMetafieldKey: String!
                        $cartBuyerIdentityBuyerIdentityPurchasingCompanyPurchasingCompanyCompanyCompanyMetafieldNamespace: String
                        $cartBuyerIdentityBuyerIdentityPurchasingCompanyPurchasingCompanyLocationCompanyLocationMetafieldKey: String!
                        $cartBuyerIdentityBuyerIdentityPurchasingCompanyPurchasingCompanyLocationCompanyLocationMetafieldNamespace: String
                        $cartLinesCartLineAttributeKey: String
                        $cartLinesCartLineMerchandiseMerchandiseProductVariantMetafieldKey: String!
                        $cartLinesCartLineMerchandiseMerchandiseProductVariantMetafieldNamespace: String
                        $cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductHasAnyTagTags: [String!]!
                        $cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductHasTagsTags: [String!]!
                        $cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductInAnyCollectionIds: [ID!]!
                        $cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductInCollectionsIds: [ID!]!
                        $cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductMetafieldKey: String!
                        $cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductMetafieldNamespace: String
                        $cartLinesCartLineSellingPlanAllocationSellingPlanAllocationSellingPlanSellingPlanMetafieldKey: String!
                        $cartLinesCartLineSellingPlanAllocationSellingPlanAllocationSellingPlanSellingPlanMetafieldNamespace: String
                    ) {
                        cart {
                            attribute(
                                key: $cartAttributeKey
                            ) {
                                key
                                value
                            }
                            buyerIdentity {
                                customer {
                                    amountSpent {
                                        amount
                                        currencyCode
                                    }
                                    displayName
                                    email
                                    firstName
                                    hasAnyTag(
                                        tags: $cartBuyerIdentityBuyerIdentityCustomerCustomerHasAnyTagTags
                                    )
                                    hasTags(
                                        tags: $cartBuyerIdentityBuyerIdentityCustomerCustomerHasTagsTags
                                    ) {
                                        hasTag
                                        tag
                                    }
                                    id
                                    lastName
                                    metafield(
                                        key: $cartBuyerIdentityBuyerIdentityCustomerCustomerMetafieldKey
                                        namespace: $cartBuyerIdentityBuyerIdentityCustomerCustomerMetafieldNamespace
                                    ) {
                                        jsonValue
                                        type
                                        value
                                    }
                                    numberOfOrders
                                }
                                email
                                isAuthenticated
                                phone
                                purchasingCompany {
                                    company {
                                        createdAt
                                        externalId
                                        id
                                        metafield(
                                            key: $cartBuyerIdentityBuyerIdentityPurchasingCompanyPurchasingCompanyCompanyCompanyMetafieldKey
                                            namespace: $cartBuyerIdentityBuyerIdentityPurchasingCompanyPurchasingCompanyCompanyCompanyMetafieldNamespace
                                        ) {
                                            jsonValue
                                            type
                                            value
                                        }
                                        name
                                        updatedAt
                                    }
                                    contact {
                                        createdAt
                                        id
                                        locale
                                        title
                                        updatedAt
                                    }
                                    location {
                                        createdAt
                                        externalId
                                        id
                                        locale
                                        metafield(
                                            key: $cartBuyerIdentityBuyerIdentityPurchasingCompanyPurchasingCompanyLocationCompanyLocationMetafieldKey
                                            namespace: $cartBuyerIdentityBuyerIdentityPurchasingCompanyPurchasingCompanyLocationCompanyLocationMetafieldNamespace
                                        ) {
                                            jsonValue
                                            type
                                            value
                                        }
                                        name
                                        updatedAt
                                    }
                                }
                            }
                            lines {
                                attribute(
                                    key: $cartLinesCartLineAttributeKey
                                ) {
                                    key
                                    value
                                }
                                cost {
                                    amountPerQuantity {
                                        amount
                                        currencyCode
                                    }
                                    compareAtAmountPerQuantity {
                                        amount
                                        currencyCode
                                    }
                                    subtotalAmount {
                                        amount
                                        currencyCode
                                    }
                                    totalAmount {
                                        amount
                                        currencyCode
                                    }
                                }
                                id
                                merchandise {
                                    __typename
                                    ...on CustomProduct {
                                        isGiftCard
                                        requiresShipping
                                        title
                                        weight
                                        weightUnit
                                    }
                                    ...on ProductVariant {
                                        id
                                        metafield(
                                            key: $cartLinesCartLineMerchandiseMerchandiseProductVariantMetafieldKey
                                            namespace: $cartLinesCartLineMerchandiseMerchandiseProductVariantMetafieldNamespace
                                        ) {
                                            jsonValue
                                            type
                                            value
                                        }
                                        product {
                                            handle
                                            hasAnyTag(
                                                tags: $cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductHasAnyTagTags
                                            )
                                            hasTags(
                                                tags: $cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductHasTagsTags
                                            ) {
                                                hasTag
                                                tag
                                            }
                                            id
                                            inAnyCollection(
                                                ids: $cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductInAnyCollectionIds
                                            )
                                            inCollections(
                                                ids: $cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductInCollectionsIds
                                            ) {
                                                collectionId
                                                isMember
                                            }
                                            isGiftCard
                                            metafield(
                                                key: $cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductMetafieldKey
                                                namespace: $cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductMetafieldNamespace
                                            ) {
                                                jsonValue
                                                type
                                                value
                                            }
                                            productType
                                            title
                                            vendor
                                        }
                                        requiresShipping
                                        sku
                                        title
                                        weight
                                        weightUnit
                                    }
                                }
                                quantity
                                sellingPlanAllocation {
                                    priceAdjustments {
                                        perDeliveryPrice {
                                            amount
                                            currencyCode
                                        }
                                        price {
                                            amount
                                            currencyCode
                                        }
                                    }
                                    sellingPlan {
                                        description
                                        id
                                        metafield(
                                            key: $cartLinesCartLineSellingPlanAllocationSellingPlanAllocationSellingPlanSellingPlanMetafieldKey
                                            namespace: $cartLinesCartLineSellingPlanAllocationSellingPlanAllocationSellingPlanSellingPlanMetafieldNamespace
                                        ) {
                                            jsonValue
                                            type
                                            value
                                        }
                                        name
                                        recurringDeliveries
                                    }
                                }
                            }
                        }
                    }
                )";
                Json variables;
                variables["cartAttributeKey"] = cartAttributeKey;
                variables["cartBuyerIdentityBuyerIdentityCustomerCustomerHasAnyTagTags"] = cartBuyerIdentityBuyerIdentityCustomerCustomerHasAnyTagTags;
                variables["cartBuyerIdentityBuyerIdentityCustomerCustomerHasTagsTags"] = cartBuyerIdentityBuyerIdentityCustomerCustomerHasTagsTags;
                variables["cartBuyerIdentityBuyerIdentityCustomerCustomerMetafieldKey"] = cartBuyerIdentityBuyerIdentityCustomerCustomerMetafieldKey;
                variables["cartBuyerIdentityBuyerIdentityCustomerCustomerMetafieldNamespace"] = cartBuyerIdentityBuyerIdentityCustomerCustomerMetafieldNamespace;
                variables["cartBuyerIdentityBuyerIdentityPurchasingCompanyPurchasingCompanyCompanyCompanyMetafieldKey"] = cartBuyerIdentityBuyerIdentityPurchasingCompanyPurchasingCompanyCompanyCompanyMetafieldKey;
                variables["cartBuyerIdentityBuyerIdentityPurchasingCompanyPurchasingCompanyCompanyCompanyMetafieldNamespace"] = cartBuyerIdentityBuyerIdentityPurchasingCompanyPurchasingCompanyCompanyCompanyMetafieldNamespace;
                variables["cartBuyerIdentityBuyerIdentityPurchasingCompanyPurchasingCompanyLocationCompanyLocationMetafieldKey"] = cartBuyerIdentityBuyerIdentityPurchasingCompanyPurchasingCompanyLocationCompanyLocationMetafieldKey;
                variables["cartBuyerIdentityBuyerIdentityPurchasingCompanyPurchasingCompanyLocationCompanyLocationMetafieldNamespace"] = cartBuyerIdentityBuyerIdentityPurchasingCompanyPurchasingCompanyLocationCompanyLocationMetafieldNamespace;
                variables["cartLinesCartLineAttributeKey"] = cartLinesCartLineAttributeKey;
                variables["cartLinesCartLineMerchandiseMerchandiseProductVariantMetafieldKey"] = cartLinesCartLineMerchandiseMerchandiseProductVariantMetafieldKey;
                variables["cartLinesCartLineMerchandiseMerchandiseProductVariantMetafieldNamespace"] = cartLinesCartLineMerchandiseMerchandiseProductVariantMetafieldNamespace;
                variables["cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductHasAnyTagTags"] = cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductHasAnyTagTags;
                variables["cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductHasTagsTags"] = cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductHasTagsTags;
                variables["cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductInAnyCollectionIds"] = cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductInAnyCollectionIds;
                variables["cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductInCollectionsIds"] = cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductInCollectionsIds;
                variables["cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductMetafieldKey"] = cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductMetafieldKey;
                variables["cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductMetafieldNamespace"] = cartLinesCartLineMerchandiseMerchandiseProductVariantProductProductMetafieldNamespace;
                variables["cartLinesCartLineSellingPlanAllocationSellingPlanAllocationSellingPlanSellingPlanMetafieldKey"] = cartLinesCartLineSellingPlanAllocationSellingPlanAllocationSellingPlanSellingPlanMetafieldKey;
                variables["cartLinesCartLineSellingPlanAllocationSellingPlanAllocationSellingPlanSellingPlanMetafieldNamespace"] = cartLinesCartLineSellingPlanAllocationSellingPlanAllocationSellingPlanSellingPlanMetafieldNamespace;
                return {{"query", std::move(query)}, {"variables", std::move(variables)}};
            }

            using ResponseData = Cart;

            static GraphqlResponse<ResponseData> response(Json const & json) {
                auto errors = json.find("errors");
                if (errors != json.end()) {
                    std::vector<GraphqlError> errorsList = *errors;
                    return errorsList;
                } else {
                    auto const & data = json.at("data");
                    return ResponseData(data.at("cart"));
                }
            }

        };

        // The CartTransform containing the function.
        struct CartTransformField {

            static Operation constexpr operation = Operation::Query;

            static Json request(std::string const & cartTransformMetafieldKey, optional<std::string> const & cartTransformMetafieldNamespace) {
                Json query = R"(
                    query CartTransform(
                        $cartTransformMetafieldKey: String!
                        $cartTransformMetafieldNamespace: String
                    ) {
                        cartTransform {
                            metafield(
                                key: $cartTransformMetafieldKey
                                namespace: $cartTransformMetafieldNamespace
                            ) {
                                jsonValue
                                type
                                value
                            }
                        }
                    }
                )";
                Json variables;
                variables["cartTransformMetafieldKey"] = cartTransformMetafieldKey;
                variables["cartTransformMetafieldNamespace"] = cartTransformMetafieldNamespace;
                return {{"query", std::move(query)}, {"variables", std::move(variables)}};
            }

            using ResponseData = CartTransform;

            static GraphqlResponse<ResponseData> response(Json const & json) {
                auto errors = json.find("errors");
                if (errors != json.end()) {
                    std::vector<GraphqlError> errorsList = *errors;
                    return errorsList;
                } else {
                    auto const & data = json.at("data");
                    return ResponseData(data.at("cartTransform"));
                }
            }

        };

        // The localization of the Function execution context.
        struct LocalizationField {

            static Operation constexpr operation = Operation::Query;

            static Json request(std::string const & localizationMarketMarketMetafieldKey, optional<std::string> const & localizationMarketMarketMetafieldNamespace) {
                Json query = R"(
                    query Localization(
                        $localizationMarketMarketMetafieldKey: String!
                        $localizationMarketMarketMetafieldNamespace: String
                    ) {
                        localization {
                            country {
                                isoCode
                            }
                            language {
                                isoCode
                            }
                            market {
                                handle
                                id
                                metafield(
                                    key: $localizationMarketMarketMetafieldKey
                                    namespace: $localizationMarketMarketMetafieldNamespace
                                ) {
                                    jsonValue
                                    type
                                    value
                                }
                                regions {
                                    __typename
                                    name
                                    ...on MarketRegionCountry {
                                        code
                                        name
                                    }
                                }
                            }
                        }
                    }
                )";
                Json variables;
                variables["localizationMarketMarketMetafieldKey"] = localizationMarketMarketMetafieldKey;
                variables["localizationMarketMarketMetafieldNamespace"] = localizationMarketMarketMetafieldNamespace;
                return {{"query", std::move(query)}, {"variables", std::move(variables)}};
            }

            using ResponseData = Localization;

            static GraphqlResponse<ResponseData> response(Json const & json) {
                auto errors = json.find("errors");
                if (errors != json.end()) {
                    std::vector<GraphqlError> errorsList = *errors;
                    return errorsList;
                } else {
                    auto const & data = json.at("data");
                    return ResponseData(data.at("localization"));
                }
            }

        };

        // The conversion rate between the shop's currency and the currency of the cart.
        struct PresentmentCurrencyRateField {

            static Operation constexpr operation = Operation::Query;

            static Json request() {
                Json query = R"(
                    query PresentmentCurrencyRate(
                    ) {
                        presentmentCurrencyRate
                    }
                )";
                Json variables;
                return {{"query", std::move(query)}, {"variables", std::move(variables)}};
            }

            using ResponseData = double;

            static GraphqlResponse<ResponseData> response(Json const & json) {
                auto errors = json.find("errors");
                if (errors != json.end()) {
                    std::vector<GraphqlError> errorsList = *errors;
                    return errorsList;
                } else {
                    auto const & data = json.at("data");
                    return ResponseData(data.at("presentmentCurrencyRate"));
                }
            }

        };

        // Information about the shop.
        struct ShopField {

            static Operation constexpr operation = Operation::Query;

            static Json request(std::string const & shopLocalTimeLocalTimeStringAfterString, std::string const & shopLocalTimeLocalTimeStringBeforeString, std::string const & shopLocalTimeLocalTimeStringBetweenEndString, std::string const & shopLocalTimeLocalTimeStringBetweenStartString, std::string const & shopLocalTimeLocalTimeTimeAfterTime, std::string const & shopLocalTimeLocalTimeTimeBeforeTime, std::string const & shopLocalTimeLocalTimeTimeBetweenEndTime, std::string const & shopLocalTimeLocalTimeTimeBetweenStartTime, std::string const & shopMetafieldKey, optional<std::string> const & shopMetafieldNamespace) {
                Json query = R"(
                    query Shop(
                        $shopLocalTimeLocalTimeStringAfterString: String!
                        $shopLocalTimeLocalTimeStringBeforeString: String!
                        $shopLocalTimeLocalTimeStringBetweenEndString: String!
                        $shopLocalTimeLocalTimeStringBetweenStartString: String!
                        $shopLocalTimeLocalTimeTimeAfterTime: String!
                        $shopLocalTimeLocalTimeTimeBeforeTime: String!
                        $shopLocalTimeLocalTimeTimeBetweenEndTime: String!
                        $shopLocalTimeLocalTimeTimeBetweenStartTime: String!
                        $shopMetafieldKey: String!
                        $shopMetafieldNamespace: String
                    ) {
                        shop {
                            localTime {
                                date
                                StringAfter(
                                    String: $shopLocalTimeLocalTimeStringAfterString
                                )
                                StringBefore(
                                    String: $shopLocalTimeLocalTimeStringBeforeString
                                )
                                StringBetween(
                                    endString: $shopLocalTimeLocalTimeStringBetweenEndString
                                    startString: $shopLocalTimeLocalTimeStringBetweenStartString
                                )
                                timeAfter(
                                    time: $shopLocalTimeLocalTimeTimeAfterTime
                                )
                                timeBefore(
                                    time: $shopLocalTimeLocalTimeTimeBeforeTime
                                )
                                timeBetween(
                                    endTime: $shopLocalTimeLocalTimeTimeBetweenEndTime
                                    startTime: $shopLocalTimeLocalTimeTimeBetweenStartTime
                                )
                            }
                            metafield(
                                key: $shopMetafieldKey
                                namespace: $shopMetafieldNamespace
                            ) {
                                jsonValue
                                type
                                value
                            }
                        }
                    }
                )";
                Json variables;
                variables["shopLocalTimeLocalTimeStringAfterString"] = shopLocalTimeLocalTimeStringAfterString;
                variables["shopLocalTimeLocalTimeStringBeforeString"] = shopLocalTimeLocalTimeStringBeforeString;
                variables["shopLocalTimeLocalTimeStringBetweenEndString"] = shopLocalTimeLocalTimeStringBetweenEndString;
                variables["shopLocalTimeLocalTimeStringBetweenStartString"] = shopLocalTimeLocalTimeStringBetweenStartString;
                variables["shopLocalTimeLocalTimeTimeAfterTime"] = shopLocalTimeLocalTimeTimeAfterTime;
                variables["shopLocalTimeLocalTimeTimeBeforeTime"] = shopLocalTimeLocalTimeTimeBeforeTime;
                variables["shopLocalTimeLocalTimeTimeBetweenEndTime"] = shopLocalTimeLocalTimeTimeBetweenEndTime;
                variables["shopLocalTimeLocalTimeTimeBetweenStartTime"] = shopLocalTimeLocalTimeTimeBetweenStartTime;
                variables["shopMetafieldKey"] = shopMetafieldKey;
                variables["shopMetafieldNamespace"] = shopMetafieldNamespace;
                return {{"query", std::move(query)}, {"variables", std::move(variables)}};
            }

            using ResponseData = Shop;

            static GraphqlResponse<ResponseData> response(Json const & json) {
                auto errors = json.find("errors");
                if (errors != json.end()) {
                    std::vector<GraphqlError> errorsList = *errors;
                    return errorsList;
                } else {
                    auto const & data = json.at("data");
                    return ResponseData(data.at("shop"));
                }
            }

        };

    } // namespace Input

    namespace MutationRoot {

        // Handles the Function result.
        struct HandleResultField {

            static Operation constexpr operation = Operation::Mutation;

            static Json request(FunctionResult const & result) {
                Json query = R"(
                    mutation HandleResult(
                        $result: FunctionResult!
                    ) {
                        handleResult(
                            result: $result
                        )
                    }
                )";
                Json variables;
                variables["result"] = result;
                return {{"query", std::move(query)}, {"variables", std::move(variables)}};
            }

            using ResponseData = std::string;

            static GraphqlResponse<ResponseData> response(Json const & json) {
                auto errors = json.find("errors");
                if (errors != json.end()) {
                    std::vector<GraphqlError> errorsList = *errors;
                    return errorsList;
                } else {
                    auto const & data = json.at("data");
                    return ResponseData(data.at("handleResult"));
                }
            }

        };

        // Handles the Function result for the purchase.cart-transform.run target.
        struct RunField {

            static Operation constexpr operation = Operation::Mutation;

            static Json request(FunctionRunResult const & result) {
                Json query = R"(
                    mutation Run(
                        $result: FunctionRunResult!
                    ) {
                        run(
                            result: $result
                        )
                    }
                )";
                Json variables;
                variables["result"] = result;
                return {{"query", std::move(query)}, {"variables", std::move(variables)}};
            }

            using ResponseData = std::string;

            static GraphqlResponse<ResponseData> response(Json const & json) {
                auto errors = json.find("errors");
                if (errors != json.end()) {
                    std::vector<GraphqlError> errorsList = *errors;
                    return errorsList;
                } else {
                    auto const & data = json.at("data");
                    return ResponseData(data.at("run"));
                }
            }

        };

    } // namespace MutationRoot

} // namespace shopify
