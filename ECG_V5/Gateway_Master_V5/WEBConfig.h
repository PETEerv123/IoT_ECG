//=========Chứa mã HTLM Website==//
#ifndef _HTML_H_
#define _HTML_H_
#include <Arduino.h>

const char MainpageHTML[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta name="viewport" content="width=device-width,user-scalable=0" charset="UTF-8">    
    <script async src="code.js"></script>    
    <link rel="stylesheet" href="style.css">
    <title>IoTVision</title>
</head>
<body>
    <div style="text-align: center">
        <header>    <div style="text-align: center">
      <header>
                        <img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAABWEAAAGXCAYAAADS7ZJRAAAACXBIWXMAABcRAAAXEQHKJvM/AAAgAElEQVR4nO3dfYhdZ54n9lOlki3PePZKkwwL2QSp3Rs2F5JRDbdJ9rKJVQYbQjbhqhPULCQgORvcfySU5e6ethdBLP/hHZvdrNU3S4hNgmVIWGhDXJWZ2cxgB0vKQBGYokt5KwjbdikhkGQza915a1svVeEpP1e+LldJ99Q97+fzgYv8Uqp77jnnnnOe7/md3zO3s7OTAAAAAACQj3nrFQAAAAAgP0JYAAAAAIAcCWEBAAAAAHIkhAUAAAAAyJEQFgAAAAAgR0JYAAAAAIAcCWEBAAAAAHIkhAUAAAAAyJEQFgAAAAAgR0JYAAAAAIAcCWEBAAAAAHIkhAUAAAAAyJEQFgAAAAAgR0JYAAAAAIAcCWEBAAAAAHIkhAUAAAAAyJEQFgAAAAAgR0JYAAAAAIAcCWEBAAAAAHIkhAUAAAAAyJEQFgAAAAAgR0JYAAAAAIAcCWEBAAAAAHIkhAUAAAAAyJEQFgAAAAAgR0JYAAAAAIAcCWEBAAAAAHIkhAUAAAAAyJEQFgAAAAAgR0JYAAAAAIAcCWEBAAAAAHIkhAUAAAAAyJEQFgAAAAAgR0JYAAAAAIAcCWEBAAAAAHIkhAUAAAAAyJEQFgAAAAAgR0JYAAAAAIAcCWEBAAAAAHIkhAUAAAAAyJEQFgAAAAAgR0JYAAAAAIAcCWEBAAAAAHIkhAUAAAAAyJEQFgAAAAAgR0JYAAAAAIAcCWEBAAAAAHIkhAUAAAAAyJEQFgAAAAAgR0JYAAAAAIAcCWEBAAAAAHIkhAUAAAAAyJEQFgAAAAAgR0JYAAAAAIAcCWEBAAAAAHIkhAUAAAAAyJEQFgAAAAAgR0JYAAAAAIAcCWEBAAAAAHIkhAUAAAAAyJEQFgAAAAAgR0JYAAAAAIAcCWEBAAAAAHIkhAUAAAAAyJEQFgAAAAAgR0JYAAAAAIAcCWEBAAAAAHIkhAUAAAAAyJEQFgAAAAAgRwtWLpSr2x8uxQU4niTJ4sTCLO1ZsPD/T6dc2FtJkmzt+W8bSZLcjv+8Nf7/m2vL1+wKAAAAANmb29nZsVohR93+cDEGqEsTQethAtWi3JoIZ7fGoa2QFgAAAOBwhLCQkRi2nooh61L855MNW7/jgPbaOKDdXFveqMByAQAAAFSWEBYOodsfnopB62J8nWn5erweK2Y3BLMAAAAAXyeEhSnEKteliVfHenuoUayWDWHsNa0MAAAAgDYTwsI+YqXrWaFrpkK17EoMZVXKAgAAAK0hhIWo2x+enQhem9bLtWpGMZAdh7K3275CAAAAgOYSwtJa3f7weAxdw2tgTyjVamxfsLK5trzV4vUAAAAANJAQllYRvNbCzSRJrgpkAQAAgKYQwtJ4gtdaWx23LdCyAAAAAKgrISyN1e0PQ2/XCzF8NbFW/b0XKmQ315avtX1FAAAAAPUihKVRYtVrCF4vmlyrsW7FdgVXtSsAAAAA6kAISyNMVL2et0VbRXUsAAAAUHlCWGqt2x+Oq15P25KtFibzurK5tny17SsCAAAAqB4hLLUTWw5cjJWvWg4waRTC2BjImsgLAAAAqAQhLLUxEb5eNNEWjzAOY/WNzcFo0AvtP5YKfMutzuq6KmfK2PeY3tXO6nrhx1vHo+JZ5wAAh7NgvVF13f7wVJIkl/V7JYUQ0r8aXt3+MPSNvSyMzdRSXL9FuR4nY4Oi9z2mF3pzl3GcXSx4n7jleLR7M3xQ4Pu9t986Hw16lwve9s90Vtf1oCczo0Ev7E9nilqjndX1OVsPoFzz1j9VFcLXbn8YLro/FcAyg7DvfBr2pRjoA9AcKwV/kpOjQW+x5ftP0dXoRW9jAIBcCGGpnNB2oNsfhuqGDeErGRqHsZdjawsAai62QLhZ8KdobUuM0aB3toSWUKpPAYBGEMJSGRPh61Z8vEzfV/IQ9q0tYSxAYxQd0l1o8a5TdAB9vbO6bqJNAKARhLBUQrc/vBArX4WvFGHcM3Yj7nsA1FfRj6ufHg16bb2Jd7bg99OKAABoDCEsper2h0vd/jBUsLwb+qzZGhQs7HPvhn0w7ItWPkD9xMmSRgUveNFhZOlGg96pEq7VhLAAQGMIYSlFbD0QJt36uMhZQeEAYR/8OE7epUUBQP0UHda18cZd0cHzrdjzFwCgEYSwFK7bH16MfV9NukXVnI/9Yi/aMgC1UnRf2NZVwmpFAAAwGyEshen2h4ux9cBb+r5SYWHffCu2KFi0oQBqoejArjMa9FpTDRt74Bb95FLRwToAQK4WrF6KEGaijxMhkd7NJElmnRm4jD5udRcGmz/r9oevba4tX277ygCosjCD/mjQC+fL0wUu5tkWBYVFB86jzuq6SlgAoFGEsOQqVhJeLXhQVBfX43KOB3AbMWy9vbm2vJHzdhkPpkJly7jac/zf9Oj9ule7/WEYaF/Ie7sAMJOVgq832tQXtuhWBKpgAYDGEcKSG9Wvu27F/rfX4p/htbG5tjxrZetMNteWJwc336g0iZNTLcbXqYl/bmsbidOqYgEqb6Xg647To0HvVEsmj9IPFgBgRkJYMtfi6tdRDFs3xn+WHbYeVlzua3srUbr94akYyi7FV9uCWVWxABXVWV3fGA16twpuvxPOCVeavE+MBr0yzvUqYQGAxhHCkqk4q/xbLVmrtyaCymuba8uNr4SJn3FrcnAUQ/fFiWC26b1nw82FMGnX5c215UYPvAFqKJyfzhe42EtND2FLqIK92ZLqYgCgZYSwZCI+vh6qXwcNXqPjSteVtoSu04gVoRtx+4+rZc/GgWlT94dQEfRW7K17oa4VzwANtFJwCNvk654xrQgAADIghGVmsRJypaEVkLfiZ1vZ00eVA8Rw+sq4Mig+vn+2oVWyYfC9ET6j9gQAlVD4uXo06J1t6kz+o0HveAntpYSwAEAjCWGZSUPbD4yD16uCtdltri2vjAdUMbC/EEPZpgSyJ+OkXS9pTwBQrs7q+u3RoLdacIXqUoODw6KrYEeht2/B7wkAUAghLIfSwPYDo/h5BK85ius2BPcXYyB7MQ7wmjC5l/YEANVwreDrk7PxfNZEWhEAAGRECEtqMTy7WsLjaXlYjcGri/6CxUA2VMWGfepC/OczNf9Ygzhp1wVhPkBpVgp+SufkaNBbbGgF51LB76f1EwDQWPM2LWnESr9rNQ9gQ7uB15Ik+dbm2vJZAWz5NteWQxAe9q1vJUnyk1iZXFenYxBbdPUQAF+2JNiK5/oiFR1W5m406C2V8KSKazIAoLGEsEwtVit+XONHx68nSfL85tryqc215ctxAikqJGyTzbXli5try6HdxfNJktys6fYJ35EPYs9kAIpXdJjXxBtvRX+m66Gnb8HvCQBQGCEsU+n2h6H9wLs1XVuh5cAzodIyVFxWYHmYQqyODa0vnokBeh29Fb87ABSr6BD2zGjQO96wbawfLABAhvSE5aFqPgHXe0mSqHituc215dD+YqnbH54K2zNJkvM1+0Tn47KfNWEXQDE6q+vXRoPeqOCnd87Ga6baGw164bx1suDPoR8sANBoKmE5UAxgi55hOAvvxX6vFwSwzRFbFVyIfWPfq9kHOxP7xDatSgqgyooO9ZrUF7boKthbDZ3YDADgASEs++r2h4s1nIBL+NoCNQ5jw3dpK363AMifvrCHV3SgrBUBANB4Qli+oYYB7HXha/tMhLF16hnbiRWxgliA/BUd7HVGg15Tju9FPwWlFQEA0HhCWL5mIoAtsofaYd2cmHBL+NpSoWds2AdiGHurBmthHMQ26bFVgMqJM+3fLHi5LtR9TxgNeoVX9HZW11XCAgCNZ2IuHqhRABsm2rgYZs+vwLJQEXECr1Pd/vBinMCryvtxWLaPu/3h8/ZjSGWrgpXvx0t4cqSK1f9VnXhwpeDt04QbbEWHsKuH/HtFV8+64U/WrqoCB2iXuZ2dHZucOgWwPwkBm1nmeZg4AdaVJEnO12BF1S6IHQ16IeR+tcC3vN5ZXVc5TCWNBr2wb35c5LJ1Vtfn7A3Tie0Bflbw236rs7pe28BuNOiFZT9Z4Fs+31ldd0MSAGg87QioSwAbHif8jc215YsCWB4l7CMT/WKLfhQ1rXe7/WHtH18FqKI44/6o4EWr7U2jGFoXGcAmKgEBgLYQwrZcDQLYMHB6aXNteXFzbXmjAstDjcR+sWEff62EQXgagliA/BTdb7TwnqoZKjpAvlnnqmEAgDSEsGxVuMdV6HkXwtcrFVgWamxzbTk8Pr9Y0T6KYyGIrfPAHaCqig5hBzXeE4q+IagKFgBoDSFsy8VH+5cq9sj2uPp1aXNtWXUEmQj7Utinwr5V0arYkUk/AHJReNA3GvRqd1NtNOiVMcmcXrAAQGss2NSEILbbHy7FQUrRF997hUrFC20NX+N2CE7FVxIrOI9P/Ng0g6Rb+wR640FoCN53WzuEx/WzWfL6CJXV3f7wWhz4lb2/j4UAdknLDYDsdVbXb48GvXB9cabA1btUQgXurIoOjkexZy8AQCsIYdkVg9izMZwrqz/sa/Gx8Ubr9ofjgHVpImxdzHi9n9xnYo1vDD67/eH4H69PhLPhtdXkQDB+tsVuf1j0LP/7EcAC5G+l4BA2XFNdrNl2LbofbN1CagCAmQhheSBUn05UxBYZxIaqzbNNDKFi4LoYBzaLBQ8A0xgv14M+djGgvT4RzF5rWoVyCP1jVexKSTcfBLAAxQjH+bcKXNcnR4PeYs0qPYuuhNUPFgBoFSEsXxPCoIKD2NXYfuB2E7ZEDF2XJl57q1Hr5sxkcNztD0dx37gWQ9nah4ehJUPcbkVXSQlgAQoSZuAfDXq3Cj4vL43b/1TdaNBbKuFmpErYQxoNepNtqyjeRmhzYr0DkJYQlm8oMIgNk29dqfsWiG0czibNCF0fpROrZXcrZrv94a24n6zEULaWF6TjCeoKbk9wQQBbbaGKbaKK/VSFK9nrZtyzemN8Q8dgloKEc9WLBa7scG1Ql+ucoqtgb876vR8NetcKPi6/1lldL7RtVpwsbakGT1S1zYksPu9o0Cu6Ldb1zup60W1HXE/lp3bXU3HSyvH+UMZkkE11c3Jf6Kyue9KkwoSw7CvnILbWFYDd/vB4HKycnXx8v6VC6Hw+vsK6WY2D3JU6BrIFtid4fnNtWQVQBcUBb+jjeKEFN1XKMu5ZfWYciI0GvXDsuNpZXfe9IE/XCg5hz4RjSk1uMhQdzFwt+P1qJVYmXxhfX1Epq24cPprrqULU4npq4nh2tsS5Z5rudHyFbOLV0aA3iuPZy+FJoLavnKqZb/sK4GAxJF2KoWlWwl2aU3ULYEPw2u0PL3T7w3Aw+yxJkncFsPsaxHXzWVhXcZ0dr+ByHii0J4h3aG/m9BYhgDX4rKBYkbIVq1IMGIoVjh0fjAa9jXixDpmLg9Isr2mmUXSFaWrx0faiq5FU6ewjbItY4fuxALay3Cx8BNdTparM9dQ+xzMBbHE6cZ1/Ohr0rsabIlSEEJaHyjiIfW9zbXmxThWSoRq42x9ejRcSgtd0xoFsmPDtaqysroU4AVlY3vcyXl4BbAWFC5NwsRoHCy4QyxWCoI/jAA7yUHT4V4dzX9HLeKtmE5YVIj6mu+FR7coTwh4ghm6up6qh1Oup0aB3wfGsMkIYu6XIoTqEsDxSRkFsCJ8u1GFtx6rXi93+cMudu0yM78R9HNZpXLeVvxsXbhbEffaljH6lALaCYp+yLT2pKic8SuX7Qh6KDlAqXwlbwjKqgt0jBhYfuN6sPK0IDhCvpzZcT1VO4ddT8Xj2ruNZpXRiKF+LPKbphLBMJQaxFw+xtkJw+0wdwqcwQ/5E1etbHp/Jxcm4bsfVsZWf2TdOHvd8BjchBEoVEx/Nybv/L4d3XhBLDooOADsxnKiyop/yUUk4IVbAvluZBeJh7Lv7iNdTeU/ozOGF66lCJomcCGCppndVxJZPCMvUYoj0fIq/citOwFXpiofYciBcVH2q6rUwD/rUxN6xlT4ZxH3/sNXgAtjqWnGzpfLOx4ACMhEnqMir5/dBKlt5Usb3ywR8X4nhlWuE+rDv7s8N7ep7Me/jfbzhWEjYy0xW9IgtlxCWVFIEsWGAs1jlCbhi+DpuFq7Xa3kGsVXBtSqHsRNtOdIM3gWwFRUvRPWpqgcTCpA1fWG/UvSyrRb8flV3RXhVG1oR7CNWPrqeqocrOV9POZ7VQ0dYXi4hLKlNEcTejBWwlbxQ2RO+umiojjNVD2NTBrEC2Gpz8VEfnUO2w4GDFH1sPh0mrKno1tAPtiRxnzjfyg9fT6pg92cizfo4mdf1VHzE3bi6Ps5X+Lqk8YSwHMpDgtj3NteWF6sYwMaer8LX6psMYyt3coj7drjQuP6QHxPAVlisgtWGoF5MJEBm4sz8s/T5PozK3VyMj44WfSwUZH3FzaV6se/u4XqqlvK6nnI8qx83UEoihOXQ9gli34uzyVdKmIk/Trj1qfC1Vs7EnrFhAq9KPYocgtjNteUwoH5vn//9kgC28vQYrZ+TesOSsaIDlSruv0UHwzdjT16+5OZSfWhFsD/7cP2czHpiptjiQGu/+nFdXRIhLDOZCGKrGsCGu3JbHveqtbDttuK2rJS4z08GseF74DH36nPRUU9mcyVLRT8WX8UBqlYEJYlVyHon1ocq2P05L9dT1sd+19X11Mk6kGc6QlhmFoLYqgWwse9reNzwLRe5jRC24Vthm1atX+xEEFvJGxF8nYFvrblQJEuFhypVquaOlUtFPx0kyPqK41m92Hf3cD1Va4sZL7zjWX3ZdiVYaN0nptHiY+uhv8mLtnQjnY79Yn8StnNVeg8LX2sl6wtPinPauiYr4dHi0aB3veAgcqlCYU7RgfCos7quEvYrzkX1oRXB/oQ39ZX1ec8ET/XlXFQClbA0RqyQ3BDAtkLYxpWriqUWXCjWWKy8gay0uS9s0edPlYRf51xUH/bd/VVqvgbSyXhmfHOu1JfvcQmEsNRenHgr9OH82AydrXIyVsVeqdrEXVSaEK/efNfJUtGVmScrdCNBP9hyORfVhxB2fwoh6s2NIBIBejmEsNRatz9cVP3aemHbX4v7AjyKEA/Y1VldD9cPtwpeG6UHFyX1chRkfZ1emvWgFQE8hCeUID0hLLUVZ8v/mepXYq/In8V9AmguF/tkrY0tCYpehpuCLGrKzQOaKquiBMUNkJIQltqJ7QfCRdFbth57vBX2De0JoLF8t8la0Y/JnxkNemXvx0WHsIIs6sq+S1O5qQ0lEcJSKxPtBwa2HAcYaE8AwDQ6q+tlhCylVcPGyVhOF/y2gizqSCsCADInhKU2uv3hhVixov0Aj3I6BrFVmokagGpaLXipyuwLW/R734q9d6Fu3DwAIHMLVil10O0PLydJ8mqLN9bNJEkm78Y/7PHJ43seMTleQtVLFYRJLz7o9ocvba4tX2nh5wdgOisFP2FT5g3Cot+76HYPkBUhLACZE8JSed3+8GqSJOcbvqXGIWsYrGyNX5try1tZvkl8RH8c0h6PFTGnGl5dHPrELm6uLV+owLIAUD1FB4WdMKN0SRWiRVfCCrKoI60IAMiFEJbKipMrhYv3Mw3bSrfigC8MvjY215YLG/xtri2PB3zfeM9uf7gUw9nxn00KZs/H/enC5tqyi2oAHuisrm+NBr2bBT81Em4MXixyK4wGvbPxKZEiqYSljtw8ACAXQlgqKQZm1xryGP0oXsyFz3Mt6+rWrMQwOLx2H93v9oenYiB7Nv5Z9MAta+MJu5YEsQDsUfQ1Rxl9YYt+T9WE1JWbBwDkQghL5TQkgL0Vg9erE9WntRLD4qvxNa6UPRtfda2SPS2IBWAf4Zz9YoEr5vRo0DsVqnALfE/9YOHRbhb8vQSgRYSwVErsWbpS05Cv9sHrw0xUyl6M2+lCfNWtQlYQC8DXdFbXr40GvVHB57Sl8Y3OvIXAt4RrK490U0eFfCcBaCchLJURg71rNQz1VmPw2prBRgyZL8ZA9mwMY4ucWXpWglgA9lopeCLQswUGPkVXwd5STUhNuXkAQG6EsFTCRAuCugSwo9g79WpVe7wWJYbPK7GH7MUaVccKYinCew2vqrnSkN7dkMTrkCJD2CJvXhYdwgqyquWZUO3d9pVArbmeYuyZBq+JUJT2VgWWgxwJYamKUzXZEqHlwOUwuBDcfV0Mo0Nl7OWJMLbqbSVOx4ueCxVYFpppq8kD39Gg5zhIk4Tg8N0iP89o0DvbWV3PNbAcDXrhRveZPN9jH0JYIEuup9jV8P2gAktB3uatYaogPt6+FCtMqyiEr89vri2f2lxbviqAPVhYN5try5fDugrrLK67qroZA2MAWi7O5H+z4LWw1JD3mDRSdQkA8E1CWCqjokHsaDJ8rcDy1EpcZ+GxitcqGLCHgbZWBABMKvpcX0SbgKJbEQhgAQD2IYSlUioUxI5icCh8ndG4Mja2nPhJRRZLAAvAfooOEE+OBr3FnN+j6EpYrQgAAPYhhKVyKhDErobqzfhIvZAuIzGMDY/+fytJkuslLooAFoB9dVbXN0poo5NbSBoD3qL7swthAQD2IYSlkkoKYsOg65nNteWzcZIpchDW7ebacti23y0haBfAAvAoRVfD5tkuoOhWBDdjb10AAPYQwlJZBQexP4nVr/qYFWRzbXkltihYLegtBbAATKPoSs4zo0HveE6/u+gQVhUsAMABhLBUWgxi85y9flz9elE4V7zYouBsAVWxAlgAptJZXS8jSMw8LI3B7umsf+8jCGEBAA6wYMVQdWFirG5/GJby3YwX9b0Q8ArmyheqYrv94ak4K/Ug4wUK4e4F2xmAFFZzOB89zFI8B2ap6CrYUeypS/VcGQ16roO+EtZF2FdD+7EN+y0ARRHCUgsZB7GjGL5mPdhhBjEkPdvtD0Pl81sZrctRrIB1cQ1AGtcKDmHzCEy1ImCs6IroOnjw/R4NeqP4nb9aUiU8AC2hHQG1EUPT52dc3vFj6QLYitpcW76SJMlvZDA7tQAWgMMqOojpjAa9xYx/51LGv+9RhFfUVSeGsh+MBr2t0aB3wZYEIA9CWGplxiB2VShXD3EbhcHo9UMusAAWgEPrrK5vxRu3Rcos+BkNeksxWCqSyU1pgpPhybvRoHctxwnzAGgpISy1c8gg9rUwAZS+oPURJ+1air170xDAApCFokPFLCtXi25FcL2zuu4aiyY5E3rG5lChDkCLCWGppRRBbAjknt9cW75sS9fT5tryhRShuwAWgKwU/Xj96dGgdyqj36UVAcwuVJNfE8QCkBUhLLUVg9iXHrL8I/1fmyFuw+/GbXoQASwAmemsrl97xHknDzOHpzHILXoiJiEsTRWC2KtaEwCQhQVrkToLkzh1+8Nwd/r8no8R+rhdqHsg1+0Pw0Bq8pXEXqmPuhAMjwSOP/vW+LW5tryV8yLnZnNteaXbHy7Fx0P39rkTwAKQh2uTs6gXILQRmPXmcdGtCG7FHrrQVOGmxsUkSTxZB8BMhLDUXnhcvdsfJhNB7M0YyNWqN1kMk5diyHoq9qKaxTcGjXE9XY+hbAgsNzbXlmszkUYIWWMQuxInTkgEsADkaKXgEDaLNgJaEUD2Xh0NelfdcABgFkJYGmEiiF2sSwA7EbqOX0XNYnwmvs4nXw9mwyDqWtXDzBjELsbqpNMCWAByFM6N7xa4gjujQe9sZ3V9lmCzyNA4KWECMyjLxfgCgEMRwtIYcQKnSovh4YX4qODJCi3rOJgNy3grDjqvVjXcDCF7rIgVwAKQmzDj/2jQu1lwj9Wlw1aXhgA3+8V5+FvOGBhDnVwQwgIwCyEs5Cz2dT0bL9qqFLweJCzji+EVA9krYTBYtX6ysdrZwA+AvK0UHMKenSHoKTqEVQVLm4RK9aU4aR8ApDZvlUE+QqVmtz8Mk2t8miTJWzUJYPc6GZf90/BZYvUpALRJ0Tf8To4GvVNT/Nx+9IOFfLkWBuDQhLCQsRi+hjvkH09MFtYE4bN8HD6bMBaAtuisroe2N7cK/ripK1pHg95iCTd8VQQezs06LjS7XAMDcGhCWMjInvD1TIPX6xlhLAAtU3TYeJi2AkWfk2+aKf7QKj+BLAc6bJU6AAhhYVZhsq2WhK97jcPYldj3FgCaqujH7s+MBr3jKf9O0ROUakVweCqI66uO7cUAqAghLBxStz883u0Pw6RVP2tZ+LrXIPaMvVytxQKAzJQRmk1d2RoD2yInD0uEsDPZqPGyAwCHJISFQ4iP4YcL6Betvwde7faHW1oUANA0ndX18Pj4asEfK01LgsO0L5jFKPbK5RA6q+sC7BqbYeI8AFpOCAspTFS/fuxxpH2djC0KVMUC0DRV7gtb9A1QIeLs3qv7B2gxISwAhyKEhSmF3q9xAKb69dFCVeyGXrEANEjRwWNnNOgtTvmzRVfC6mk6u6t1/wAAQDpCWJhCtz+8EAccRfdbq7Owrja0JwCgCTqr61tJktwq+KM8MlyNQW2nmMV5QCXsjDqr6+G68nqtPwQAkIoQFh4hth94t4QBThN0YnuCi21fEQA0QtHh4zQVrhcKWI5J12OPXGbn+ggAWkQICweI/V+vaj+QibfiugSAOis6hD09xSRA+sHWVJzc7KW2rwcAaAshLOwjBLCx/cB56ycz5wWxANRZfIR8VPBHODBkjQFt0a2S9IPNUGd1/YpJugCgHYSwsMdEAKv/a/ZCEHstrmMAqKOiQ8iHtSQougr2VqzeJEOd1fXQUuI16xQAmk0ICxMEsIU4E9axIBaAmir6cfyHBa3T9IzNklYEOemsrl9OkuSZEiZ/AwAKIoSFr7sqgC3E6RIGjgCQhaIrYTujQe+gc+ag4GXRiiBHod1FZ3U9tJh4XhgLAM0jhIWvu1xCr7c2em9zbVl/WABqp7O6vpUkyc2Cl/sb1bAPCWZz01ldVwlbgM7q+tUYxv5GbFNwvfEfGgBaYMFGhq9sri1vdPvDpVjp0bFqcgoWRfkAACAASURBVBEC2AsN/FwAtMdKwU/OhMD14p7/VnQ/2NWC36/1Yv/dBz14R4NeaOW02Pb1so+PK7dEALAPISzsIYjNlQAWgCYIIeyrBX6Ok6NB71Sswh3TD7ZlOqvrt7WE+KbRoFe1RQKAfWlHAPsIQew+FSfMRgALQCPECsWi2xc9CF1Hg16ohjxZ8PsL/wAAZiCEhQPEnqXPWz+ZEMAC0DRFV4ZOVr4W3Yrg5p4qXAAAUhLCwkNUOIi9FSdp2O9V9GQhjyKABaCJig5hz8SeoEkJrQhUwQIAzEhPWHiEEMR2+8PwQ++WsK5uxQkZrsU/tzbXlqeqROn2h+PJG8avpRIeXRTAAtBUZQSTS6NBL7zvmYLf92rB7wcA0DhCWJhCwUHszTjYWZk2cN3P5tryePKGB4PEbn94KoaxoYJmkNcHiG4KYAFoqjBJ0mjQu15wIFp0BWwwij1wAQCYgRAWppRzEHsrBq9XZwleHyX+7t33iZWyF+IEZFlXyN4soV8dABRtpQUhbNFtFwAAGkkICynkEMRej8Fr4Y/5xUrZK+HV7Q/PxjA2i4HkbgAbfz8ANFkIKN8q8PN19IMFAKgnISykFIPY4zMOukLl68XNteVKVJfE5Vjp9odLsVL2sJWxAlj4utC/8XKD18mpCiwDlKazur41GvRuFdxzvVPw51UJm7GGnxcgD66ngEYQwsIhbK4th+rRMNnV+ZR/e5QkyeXw96u43jfXlkO1y6luf3g5VsamGegJYOGbzpQwgQ5QrBBSvtjQdX4z9L6twHI0zattXwGQkuspoBHmbUY4nDjp1Hsp/nJoPbBY1QB20ubacghhF+MyT0MAC0BbNflx/cLbJQEANJUQFmaQIoh9bXNteSnPSbeyFpY1LHNY9kf8agEsAK3VWV1fiU+6NJF+sAAAGRHCwoweEcSGQdkzsbK0luKyf/eAAaYAFgCaGVbe6qyub1RgOQAAGkEICxk4IIi9FQPK2g/M4sRdS3uCWAEsAHypiZNXqYIFAMiQEBYysieIvRn7vzamgiR+lqUYLgtgAeArTQwsmxgsAwCURggLGYpB7GtNDShjELsogAWAr3RW17fiDcrGiL1uAQDIyIIVCdmqc//XaQhfAWBfoRr2dENWzWoFlgEAoFFUwgIAwOyuNmgd6gcLAJAxISwAAMyos7q+sWcCyzrTigAAIGNCWACgLhoz2SGN1YTw8mbscQvsz7mIuvO0A5RECAsA1IWe1FRdEwa2BufwEJ3VdeciAA5FCAtAm6juAvLUhEpYrQiAR3E9BXAIQlgA2sSgod48AkqlxQq56zXeSqPO6rpKWDjYTetml+upenM9BSURwgLQJi4662vkEVBqos6VpKpg4eGEj19yPVVfrqegREJYANrEoKG+bDvqos6VpKpg4eF8R77knFxfth2UaMHKh3rq9odL+y345tqyi0M4QJjxezTo3UqS5KR1VDsq9KiFzur6Ro2PM75n8HCus11P1Z3jPJRICAs10e0PTyVJcjFJkhC+nj5oqbv9YRL7VV0NJ9nNtWWPTcHXhYvPF62T2jFooE7qeJy56RFVeKhb4SaLVfSA66l6cj0FJdKOACqu2x8udvvDcNf903ihc2AAOyH8zFvh73T7w6sxwAW+dMV6qJ3roeqm7SuBWqljtZyBOTzcVevna1xP1Y/rKSiZEBYqqtsfHu/2h+Hi5mdJkpyZYSnPxzD2sm0NXz5CV/PZy9vIQI9a6ayu1zHQFMLCwUbORV/neqqWjAehZEJYqKBYuXot40d8Xu32hxsh3LXNIblgFdTG9ZoGWrBaozXgMWt4uCvadezrYgWXif2F6yk9jaFkQliomNB+IM5aOU3bgbTC77wmiKXtYvXGa21fDzUwEphTY3W6eWBgDgcL4ZUKwn3Emzeup6rP9RRUhBAWKiSGo2HQ1slxqQSx8OXAIQyo3rMuKu2C3mXUWJ2CTdXmsL8w2e1Z6+ZgrqdqwfUUVIQQFqolDIJOFrBEp/W1gt2BwwUDh8p6XhsC6iwOeG/W5COohIVvCt/fJW0IHs31VKW5noIKEcJCRXT7w4szTsCV1vluf+jOPq0XBw4epauOW0mS/EZndd0s1DRBHcLNVSETfMOqADYd11OV43oKKkgICxUQWwOU0WtKNSx89Sjdt8zyW6pRHLwtmiCIBqlD9ZEqWPhKuA54prO6flYAm57rqUpwPQUVtmDjQCVczLkP7EFOdvvDC5try+6Q0nrx0eGl0aB3Kn4nzxbUHqTtVmNQtWLAS9OEmahHg96opHP8tDymStvdit+Dq0Kr2bmeKo3rKagBISxUw8USlyK8txCWNLYKrnAodEAUBw/he3ExDiAW4+t4/JPZhKq7MDjYCAFVA9blbRU/PEJ46mSpoivpdo0nayk6LMtyPTlmlGdrYltei+eisgIr11Mc1u24Pcu+nnINlC3rswXmdnZ22r4OoFSxL+sHJS/GtzbXls2YCQAAAJADPWGhfFWojqlqhQ4AAABA7QlhoXxVeBzHI0EAAAAAORHCQvmEsAAAAAANJoSF8lV5xmQAAAAAZiSEBQAAAADIkRAWAAAAACBHQlgo38g2AAAAAGguISyUb6MCy7BVgWUAAAAAaCQhLJSvCiFsFZYBAAAAoJGEsFC+a5YBAAAAoLnmdnZ2bF4oWbc/vJ0kSaekpbi1ubZ8yj4AAAAAkA+VsFANV0tciiv2AQAAAID8CGGhGkIQOiphSUYlB8AAAAAAjSeEhQrYXFveKqki9eLm2vJt+wAAAABAfvSEhQrp9ocbSZKcLmiJVjfXls/a/gAAAAD5UgkL1XK2oLYEN5MkuWDbAwAAAORPCAsVEtsSLOUcxIYAdkkbAgAAAIBiCGGhYjbXljdiEHszhyUTwAIAAAAUTE9YqKhuf3g8SZLLSZK8mNES/mRzbfmi7Q0AAABQLCEsVFy3P1yKYeyZQy7p9SRJLsYKWwAAAAAKJoSFmuj2h4txMq0wedfJRyz1rSRJVpIkuRL7zAIAAABQEiEs1FBsVRBC2VPxFWzF14aerwAAAADVIYQFAAAAAMjRvJULAAAAAJAfISwAAAAAQI6EsAAAAAAAORLCAgAAAADkSAgLAAAAAJAjISwAAAAAQI4WrFzqavvGpcUkSY7HxV864GNci3/enn/69Q0bGwBgdt3+8ESSJM/G11NJkvSSJDkx8Ys/S5JkPUmST5Ik+Si8NteWP7PqAYC2mtvZ2bHxqbTtG5eOx5B1Mf55KkmSk4dc5ltJkmzFcDaEshvzT7++ZQ+AYnT7w14cqI8H7EkcwBchBADP2dTQbt3+cKqL38215bm2r6v9xPD1hSRJXt4Tuj5KCGDfTJLknTqEsd3+8Kn4Gcchc5HW4/r6WpAtxIava+PxvI6fuY3X//EzPxvPk0V/5v08t7m2/FGJ70+kEpZK2r5xKYStZ2PoejrDZTwZX2fG/2H7xqVbMZS9FkNZFbOQoTiQDQP2cyUMZAHISBxUvj0xoEwjDETfCOeCbn/4/c215fWqbpd43vrDlCFzlibX77mJ5Qrr7P26BNlAe7Xx+r/bHz4bP++5Es8fVJwQlsqIweuFGL52ClyuEMqej6+wHKNYJXstVs0KZuEQ4oXIyyXf9QUgAzGA/TCDgeXu7+n2h89VOIhNW+VblHE12cvd/rA2VcVZmKb6T/U6lK+N1//GPKQhhI1Gg95BPUXb4nZndb3woHH7xqVTMXi9MEOLgax1YqXsZLVsMtHKIKyn2xP9ZkNIe7siyw6li4+qvhxfADTD2xkGkyfi7/tORddM1QfS46riEMZ+zyOmQNnaev3f7Q/fMOYhDSHsVz6uyoKU5PpDJrfK3ETV6/karaO9rQxeHf+PGNImcT2OjcPasa34OsiW/rTUXXz06KeHfFQVgArq9ocv53Bc74Xfu7m2/GYFP3JdHp09EauKQ3uHdyqwPEALtfH6P4bOHxrzkJYQlkJt37gUgteLGfd5rZIzE8tyJu1yTYS5ebq1Txg8GRCP//m2NgykkeGjqgBUxER1Ux5CJaf+prN7u9sfJoJYoGhtvP4XwDILISy5275x6Xiser1YoZYDbXZyn+2wb2C8pw3DtXGvXO0X2CtejGT5qCoA1fBCjsf2E/H3V7Eatm5CELte5QnPgGZp8fX/GwJYDksIS25i+HoxvoqcaIts7W3DELbtzSRJriZJsqKFAtFhZ8sGoNpeyHnpzglhMxOCgeca8lmA6mvd9X+chCvv8yINJoTlgW5/uPSwvrCba8uXp1lbcbKtyzXr99oqO5//ebL9+Z899CPPLTyWzD95YHYe2km8FV7bNy69F7a3MLa9uv3huTiIBqBB4mAz7/6ooTdsTwVnJp4N5+TNteX3G/BZgApr8fW/SbiYiRCWSUuTk03t46EhrPC1Hn6x9mGy88Uvpl7WucefSOaOHUuOHP+1ZP7EP7X75x5he5/dvnEpBLFXWrxq2+yNtq8AgIZKM8AOIWroSfpJDG5fThHgnot/v27CMufRz/bZGf5uWJdCWCBvrbv+j/1vZzk+gxCW2Qlf6yNUwKYJYIPw8+G1Pfpstzvs3MJCcuQv/rPJ0X/uLydzx35p/GOdWBV7av7p1y+2dgW3ULwLfpgqqU/iIDEMYD9RAQVQLbHX37SPXIYg8rnJCba6/eFHSZL8fMq/H97nlZrtAqH/6nfy+uVxtvFzcd2kOc+eC9vOZGdAXlp8/X/Yyt9wg/KjeN74JONlomaEsByanq/1c/9PZp9Pa+feveTe/7W1+1r4S6eSx77VTZKFo+P//eL2jUth4q6VMlfOFx+8FPbNs7G6+9TE/wotE648/t23NkpcvKZJezESLjzeNIMzQOWl6Xn35t7QLww0u/3hO1P+nhM1fIw+15AzDtTfjOvw7ZTn22dVwwI5auv1f9r+tyF4/b7glUlCWA5l+8alCyHMEr7Wy86f/nGmyxuC2PujP0qO/Yv/ymRVbKiKLiWE/eKDl8ZV2f92kiS/ss+PhMnFzt9Z+cF/+NjZv/eflbCITZTmIixciHyvLdU5sZdiksOEBeEu+kcZ/86pZPCZdiseylr+h4mPmPUaNMPvZ3HQU8n1TS2kCWEPGlhPG8ImHqPfXzxnfq/bH/40xTk37z6+uen2h4fut3iIv/t+GeFIk8+ltEZbr//TtCII1+smSuQbhLCksn3j0lIMX09bcyS7we6fJJ//L/9j8sR3nhmvj9OxLUFhE3V98cFLS3Nzc/9RkiT/zjQ/v5Mkw7u/+6M/OPrX/+7/lP/SNVd8FGla620IYCcmKchzooJX4gVt7mIweS5edGYWJnf7wyTuEx/FQXBpj6PFR37fbnKPr7i+P5lY5x+pyuBhUk7I9f5Bx/bw3e72h59M+bvCY/RP2TcP9Eo8Tk1zo6i2IeyMfSbT/t318c2qPLXhXEp7tPX6P14vpvG9cpeYqhLCMrXtG5eu6vtab/dv/+Nclj8EseF3T0zadSo++p+r3fB1fv4/T5Lkr+zs7KRY4J0jyU7y3yRJ8pfzXsaGS3Mx0ugAtmlBXrzAfiHnzzOuPH059o58p+hHkWPPy5/mUK1cRU/F17n42dfjOtcahP2kGWQ/6nv7TopwLLzvm7bIN8X2Du9PWVlc5xC2MdpyLqV12nr9n+Zzv+OGIgeZt2ZIQQBLJdz5b3/4ozsrPwi9FT7e2d7+K4dZpu1729+OfY05vGmDq1Ie9ytKrHD5wyYEsCFM7vaHH8ZgssjPE97rp+G9D1FpMItzLQlg9xM+99vd/vCfzPL4L82TckKuT6YIfNIEQmlaILSRSscaaOG5lHZx/f9ojtUcSAgLLTJ/7Jdz+7B5/u4kTrZ193d+9MadlR/82c797b+zs7OzX8/X6e3sJPf/7O6FXBe6+abtndnYnmUTlZS17yMaK3bKDpPDe/9hykfdZlHU+1RZ2Hff6PaHfxhvKEAWvWAfiIPwaYPYp+yHD6WyquJaei6lXVp//T8Fx2oOJISFFpmYPCtTC3/p1N7fvZHV77/3ez8+efd3frSSzM390fbd+y/v7Oxk9iHmjmhHMKNpB8pNvgh7oQmPfXb7wxcqFCafiJU8RVTEqRT6Svg+f1jQeqfasmxFMJbmPGAfnJ0AoAQtPpfSLm29/ndcJRNCWGiRuSf/QuYfNgSwj/3zvz75n1bnn3799qy/997v/fhfvfs7P/pH9z+/9+n23fuDZGcn8+PV3MKRv7p949KV7RuXru15XYmT0PFwUw0yGv4oUu0f444T8LxdgUXZ6+0CKuKEsF93Iq53g/aWit+5zB81jb2Hp+0LqHrvYNOGe8KCgrX8XEq7tPL6P+Xnqf0TcuRHCAstsvBr/0wy9/gTmXzg+c6J5PHF/t4AdpQkycVZfu+9D1/+G3d/90f/9/1f3P0ftu/e/3ayszM388JOmptLjjxxNDn6q08kcwvz4aL0xSRJzux5hf/2cZyMDvYVH/Or9UXWRDuFqvowLiPFMmhvrzQBfNrJf6b9+RNuBBxo2u+lfoQFci6F1pi2utc1FAcSwkLLPP4v/cuHDmLnnvyV3crXY985kxz7jX8tOXL81/b+yMX5p1/fSvt7wwRZ937/x2/c+e0f/uL+n975B9t37v/FrLfK3Px8cuTJx3bD1/lfOrobxk7h/PaNS/rGcpAmVFG+XfEg+USKWdXJ1k8N2tslbu9pq1A/O8QM7I/sHztBNeweKSdME8IWy7kU2mHaY+s511AcZMGagXaZf7KTPNF/Ltn+01Fy/7N/nOx8/ue7/7zX3MLRZP7J40mysJDM/0onObL7z0cPWlfhF5ydf/r1a2lW5vaNS6fu/9ndKzv37v/1nXvbuRyP5hbmk/knjibzjx057K+4nCSJilj2k2bSjXfio7uV6Y8VH51MG3S8Ey9AP0n7WeL7PRXXW5r3faHbH5a57r6zubacW6DR7Q93HvUzm2vLqZ8IiJWsJ2I1Ri+u9zQDgqdi4PNm2vemttJU96cJVHeF71G3P/xkyhtYz4bZ3Vs8s/Z+3phy+4Tj5bStHyrnoONdXsfKWTmXQqu8P2UrsqfiMfv7dg/2EsJCS4UwNrxmFMLXK+GVpg9sCF+3f3H3v9r+/P5f29nezmUDzD++kMw/sZDMHZm54P9k6A+bNmCGCd+P/RCrJk0/2xDEvTnLwH5i4PdOrA54I0VV18tlTfCQZwCbp4nl3l1vE1WOL6eo4n6j2x++U+dAh1TStAA47DHtnRQVeefcBHjw3X07ReBWxfNNkzmXQkvEm4kfTVmIEW58hD9fcR3FJCEscBg3Y3Xo1TTh6/2P/9a/uf35/b+//cW9k8nOIwsa0pub2w1fjzxxJEnmM+22EibpEsKy1zQXYO9UMYANFWYpKnkzD5Hjxej3u/3h+pQTmaiKm1Fc52HQ/n7KQbtq2BZIOSHXRzN8F99PEcK2dt+L22Oy2nHaCmWVjgVyLoVWejPF9/6F2Jrg/XgD5JO63twnO0JYYBq3kiTZiEHkStq+r/f++1d+tPPF/Ve379x/Mo/wNfR7nX/iyG4AO2WvVyhK2p6JRZm2ouqVPEPk8LsnKnkeRVVcBiYG7Z9Mud6FsO2Q54RcD4TwJw5GpzkGPRUeva5wqPjsNI/IF2jdo6+Fcy6FlgnnpG5/+EqKG4rjft6759lYHVu4Mtq1sD8hLBRvFAPNSVlWWS7t+ffjSZKcfsjPh6rWyWrWjfjvIWjdOuxj+GGyre0799/YuXP/393+4t6Th/kdj7Lb7/XYwpfhK5VVoUHqc0UP5iscHkwzcAzVbrkP1MJ7dPvDc1NU4Rk4Ziiu994U+0IIwnoqNxovzYRcs4ZJH6V4v3Men55K+H5+zyOvhXMuhQM0+fo/ft+eSnkDE3ZJLiB7o4mq0dvjUHP+6df3Bq+NtNvv9fO7/+n2F/f/9bwm2wqh69yxI8n8wqEn20qrFduOdojVMtM8dlxkG4V3pniUsheWXciQqVemDBGeNdt6c3X7wxfynJBrr1i1N+0kU6Gnnn56D/d+fNTdOiqQcym02+bacniq6LOUfaFBCAuZCY/Zb+/8e/PP/NZ/3caVun3j0uL2L+7+/dwm25qbS46Eqtdjmfd7fZTR/NOvrxT5hpCzaQaNodqtsFYKKUKZnqq47KR4NHzaibyopzQzrGcVKL2TYuB6zmRT+/oo9h2vatubpnMuhZbbXFt+JU7U9bZrJaZVaJIBjTY3l2zfvf9f3Pvw5b/Rpg0dJtu6+9/9eOvuP/nFz+7/+d3MA9jQ7/XIk48lR08cS+Z/6WjRAWxwpeg3hJxNM3AsY1A/zXtOO3EQ05tmIG5g0VApJxZaz3BCnzTHGI97ftNncRIuAWx5nEuB3dZjm2vL33Zjg2kJYSFD88eOHtu5t/MP7v3ej//Lpq/XMNnW3X/4m39y7/bnv739+d2TWU+4Ffq9HvmVx5OFEL6WN+HWLSEsDTTN4KuMmZOneU8Dx+xN02ZACNtcaQLOzKpRY4/haVtc9GJYzFdCpePb3f7w52HyMuulFM6lQLiZeS4ci1Pc0KTlhLCQsSO/HKo1k3//7u/+6H8Lk1M1af2Gz3Pvw5ev3vntH969/8df/J3MJ9yam9sNXEPV60LnWDL/WGE9X/cTevuenX/69dvp/ypU2jR9GMvo/znNe07bt5IpTTnhlgCsuaYNYT/LoapPNezswnfzw25/qCdh8ZxLoeW6/WFoQ/BT10mkIYSFHMwfO5rMPXake2/0+f9593d/9Ot1X8f3Pnz51+/9/o//4N5nn//R/T+9cz7rCbd2Ww48cXQ3fA2tB0poObBXCGCX2jKZGq0zzeCrjOqdaSYJMXCEjKSckOv9HCbySVNZm6ZvbRu9EcMAiuNcCi0VJrfr9oc/dYOQwzAxF+Rkdwb/hfkn7//xnZ/d+e0f/r3H/q3/5Dfrtq5Df9udO/f/4+27292s2w0kseXAfJhs6/FKHYoEsDTdIx9DzLDv49RCRWa3P3zUj3uEErJTxoRcD4RQd8qJ4YKnwiOfFeuBGioOX8npdz8VX+dSVFi90O0PQ99ek5gVw7kU2usNNwc5LCEs5GjuyHyy0Hls/t6f3PnRndUffndne/vZx7/71lbV1/m93//xGzt3t//m9t37/3Qevz+ErvNPLOyun4q5rgUBAE13iAm58nqsetoQNok/V6UQNsx8n/dELK/Enq/TzrwdKmLzqFoGIPaATVkB+0k8d4XzxSdl3JyhWoSwkLf5+WThLzye3P/TO9/euTv3v99Z+cGrj539e79VtfV+7/d+fHJnJ/mtnTv3z+1sZ9tuIIktB+YfP7IbvpY0ydbDhOrXy/NPv24SrnzkVSmUlosegC+VMiHXXqGytdsffjbl49Fh8pMTbQsYQ9Db7Q+/E3q/TlHBeCJWaH2/oMUDOEhTr//fSPGzr2yuLb+Z8ftTc0JYKMLc3O5M/3N/fvfo/V/c/dtfrPzgbyY7O//B499961rZ6//uP/zNfyPZ3vm72/e2/4VkZyfzdLSiLQcmvZckyUXVr/lx8QFQOdNWn+YxIddeIeSddmKpEB637pwSWzc8lyTJz6cIrENY/YpqWKBMTbz+j1Ww07aI+b72MOzHxFxQoPlfOrobxiZJ8u0kST7+4oOXrn7xwUunit4GX3zw0vG7v/OjN+6s/vCPtr+497vbd+93sw5gQ+i6cPxYstA5VtUANoSv35p/+vULAlgA2iLlILKIR9vThLyt7cEXt8M0A/oTehUC5GLaY+tHAlgOIoSFgs0/diQ5evzx3QrRJEnOJ0ny6RcfvHQlBKN5L8kXH7y0eOe3f/gHydzc/7d99/7LO9vbv5rl7w8tB4788tHk6K8+kRx58rEq9nxN9oSvle/PCzl4ZKASHvktesVP+Z4qu2B2aQK63Huwxn6z0/ac7XX7wzZPKjRtD9ppQ3YOz7kU2mfaXuoCWA4khIUyxD6xExWiLyZJ8n/EMDbTytjw++6s/OBv3Vn5Qaj2/NnOve2/luzsHMnyPUKwHCp8F04cS+aPHa1iz9dE+AoPTBN2lBFyTPOeeU0OBK0QJ+SaNoT9pICJp8ZUw04hxfYw+33+nEuhReL5c9obK0WdO6khISyUJfSJffKx3VcMLX8lhrGfxjYFZw+7ZCF4/eKDly5+sfKDfxR+387Ozt/e2dnpZPpJ5+Z2A9ejJ47tBrAhiK2oVeErpFZ49Y7KLQo0VRVYQysu0wSYRVbypHmvNJOKtZUQthqcS/PX5uM5xZr6u6UnNw8jhIWShWrYifYEY6FNwQdffPDSVqyOfWQgG1oNfPHBS5e/+OCl/zkEr0mSvJXs7Hw7608XljMEx7stB3756G5Vb0VdT5LkmfmnXz8rfIWvmebufBmDlWkublUWkIWpH31v4NpOE2AWFsLGAeu01bAnuv2hIPbhygj/2sa5tBrafDwHaqiy05VDq4T2BJ1jyfaf303u/+Lu5Cc/GatjX/zig5fCv99MkiQEihvx/4c+sotJkpzJdXWFqtfHjiTzTyxUtc/rpBC+Xp5/+vVr1VkkqJRp7s5P2/MqS9O8p8oCsjDtfvRsk/q6pZyQ650SKnneT1Gp26htMy3VfJXiXFoNrTyeU4qpj7+hdcHm2vInNhP7UQkLFTL/S0eThePH9lbFTjqdJMkgSZJX4+vFPAPYB1WvoeVAdSfaGhtXvi4JYOGhpupjF3tfFSIGC/rYUZRp96NzRX4PClCpCbn22lxbDu857aC1adtmWmWEeuzPubQa2no8p3hpvjeO1RxICAsVE4LOUBV75Imj5SxYqHp9fGE3DA7LsTt5WDUn2hoTvkIKcSbyaSpHXi5wvU7zaPEncdlhVmmqU35axgznWavwhFx7maDr4aZtw+BYmTPn0spo3fGcWijye0/NCGGhokJVbKhAfUhVbKa+1uu1+lWvifAVZjJN0PFCEY++dvvDZ6ccOOoHS1bS7Eu9hgzcqzoh1yzv3aq+qvK1wgAACV9JREFUsN3+8O0U7SSa2LrlkWFbCe0anEvL18bjOeVIc1x9qtsfCmLZlxAWqiz2ij3SeTyZy2ECrPA7Q8VtCHsfVL1Wn/AVZjftoOXDPAcrcWD60yl/XAhLJlJOApXExwr/sOaTQaVZ9sJbEYzFHnrTVuk91YYeqeEY3O0Pf5pyGzbxeDlNxWPR+4NzaclaejynBIeoIH+j2x++IfRnLyEs1MD8wpFkYdyXddYwdrLdwIljuxW3SQ4Bbw6Er5CRFL0Xw4Xjz2OFTabi7/xwylm8P4nLDFlJuz+FCsS3u/3hz+Og6lxdAsD4XZu2gvL9CkwmUpdq2DxDtafiPhaqX39+iNYLbb1pVWjlmXNpZbTmeE7p0u5rL8fvftjPnhXIEtSi7A34UghPw2v7zv1k+xd3k51729OtmRC8PnYkmXvsyO6fNRPC18uCV8hcCDremOKXnohVPB/Fi8/3Dztrerz4PBdfaQajb9r8ZCkEEd3+8JMU4eTYU5NBT7c/zHu7fLS5tvzcjL+j0hNyHbAMb0/5syE8eeWwx6QZhUmXdkp430dpav/sj6Y4b4Tw+u3NteXvF7RMiXNp+Vp2PKdcHx3iptiJuJ/t7msF7GcHCedK19MVIISFGpofh6nb27uB7M7d7WT77naS7Hw1Fgg9XuePHknmHj9Sh/6u+xG+Qr7eiVVk0w5ano2vt+NgJ2213FOHGCAlMVAos0clzfVKikd4aymGNdNWi1aiSi4EU93+8J0pl3scRjlGfKWp62Lac84LsTr0nSlaW6xnEOA7l1ZD44/nlC98h0JVa55PQtB8Qlios/n5ZP7YfJIcS5La1bceTPgKBYhBx2EHLYcdBB5GkRVNtEisnnq/4bPsp3lcv0oBzUcpll0I+5VPGrwu0rRYeGrK6tTnZm3d4FxaDS05nlMNb055fIF96QkLVIWer1CwWPVW5QH7m5tryybkIk/fTzERVB3VYkKuvVL02gxCn72igqyqK6s1Q+4OMQFTkcvmXFoNTT+eUwHxkX77GYcmhAXKJnyFEsXeeVW8mAy9016pwHLQYDHYCd+BxgVXNZyQa680gZvqty+DtqZPYFjZoNO5tHxNPp5TOc/ZzzgsISxQFuErVMdzFRs8hiDhexVYDlogTmJUte9AFtIEk1WskksTuKWp+G2iN9sQtMVqzipXdDqXlqzBx3MqJAb+zx2ipzMIYYHCCV+hYsLF5Oba8ncqMnNyeJz2e019pJZqmhi4N2Lm4JQTcn1WxQl7YmXutEHKU7HyNyt1GVjvVv617KmB71W1As25tBqadjynmuJ+9p2K3xiigoSwQFGEr1BxcSBfVgXJ7qAp9tqCwsUA5ZUsJuupgDRVsFXuZZlm2bJsSVCH7R/WzbcbPuP9N0xUoFW20tG5tHwNO55TUXE/ey7eHFIVy1SEsEDehK9QI+Fxz1jJ81xBk6C8HweM3zEJF1UQvwNh//92rKSq48AqzeP5VQ7x0hyDXogVwFl4s6LVlmFffCWGr99v6xMDE5WOr1S4Kta5tAIacjyn4kI/7s215W/HMLZVN8ZIb8E6A3ISwtfLgleop3HvvRhqjCf4CX+Gf+8d8kOtxwHzR3Eg9JG2A1RVfBw+hDyvdPvDXtzvn5rY/7N8/D0z8bH8ab+jH1VwQq4HwvGh2x++kyJUPpfFADisk25/+Fx833PxuFe0cZD20fi4WeVtVbR47gih2pvd/vBc3OfH39FpJ6TLnXNpNdT1eE69xMkRw+v7E+fi8TFplu88DTK3s7NjeyZJMhr02r4irv/V//d8CMtePegH/tc3/58Qqp0pdrGoIeErAAAAwASVsEwtPE4efnb7xqXwZ3gtxj871iLCVwAAAID9CWFJLYZsD4K27RuXFicC2fDnaWu1VYSvAAAAAA8hhGXSVgzUUpl/+vWNJEnC62ryZSh7fCKUHQezqmWbR/gKAAAAMAU9YSM9YZPrndX1pbx+uWrZRhG+AgAAAKSgEpZC7K2WTb7ZWza8TtoalSZ8BQAAADgElbBUhjYGlSV8BQAAAJiBEJZK275x6dREpaxgtljCVwAAAIAMCGGpHcFs7oSvAAAAABkSwtII+wSzp/SYTU34CgAAAJADISyNtafH7DikPW2Lf4PwFQAAACBHQlhaZ/vGpXHF7KmWV80KXwEAAAAKIISFr1fNLk5UzTa116zwFQAAAKBAQlh4hO0bl8bVsuPK2eM1bWsgfAUAAAAogRAWDim2NTg+EcwuVrS1wc0kSS4KXwEAAADKIYSFHGzfuHRqonp276uokPZWrHy9ahsDAAAAlEcICyWJbQ6SiYA2idW0x+M/p217ENoN3E6SZCNJkpX5p1/fsG0BAAAAyieEBQAAAADI0byVCwAAAACQHyEsAAAAAECOhLAAAAAAADkSwgIAAAAA5EgICwAAAACQIyEsAAAAAECOhLAAAAAAADkSwgIAAAAA5EgICwAAAACQIyEsAAAAAECOhLAAAAAAADkSwgIAAAAA5EgICwAAAACQIyEsAAAAAECOhLAAAAAAADkSwgIAAAAA5EgICwAAAACQIyEsAAAAAECOhLAAAAAAADkSwgIAAAAA5EgICwAAAACQIyEsAAAAAECOhLAAAAAAADkSwgIAAAAA5EgICwAAAACQIyEsAAAAAECOhLAAAAAAADkSwgIAAAAA5EgICwAAAACQIyEsAAAAAECOhLAAAAAAADkSwgIAAAAA5EgICwAAAACQIyEsAAAAAECOhLAAAAAAADkSwgIAAAAA5EgICwAAAACQIyEsAAAAAECOhLAAAAAAADkSwgIAAAAA5EgICwAAAACQIyEsAAAAAECOhLAAAAAAADkSwgIAAAAA5EgICwAAAACQIyEsAAAAAECOhLAAAAAAADkSwgIAAAAA5EgICwAAAACQIyEsAAAAAECOhLAAAAAAADkSwgIAAAAA5EgICwAAAACQIyEsAAAAAECOhLAAAAAAADkSwgIAAAAA5EgICwAAAACQIyEsAAAAAECOhLAAAAAAADkSwgIAAAAA5EgICwAAAACQIyEsAAAAAECOhLAAAAAAADkSwgIAAAAA5EgICwAAAACQIyEsAAAAAECOhLAAAAAAADkSwgIAAAAA5EgICwAAAACQIyEsAAAAAECOhLAAAAAAADkSwgIAAAAA5EgICwAAAACQIyEsAAAAAECOhLAAAAAAAHlJkuT/B8YYUM1W7whuAAAAAElFTkSuQmCC" 
                        alt="Logo" style="width: 400px; height: auto;">
					</header>
    </div>

<!-- WiFi Configuration Section -->
<div id="configWiFi" style="; text-align: center;">
    <table style="margin: auto; width: 100%; max-width: 500px;">
        <tbody>
            <tr>
                <th colspan="2" style="padding: 5px; border-bottom: 0.5px solid #c8c8c8">Thiết lập WiFi</th>
            </tr>
            <tr>
                <td style="text-align: right; padding: 5px">Tên WiFi:</td>
                <td style="text-align: left; width: 50%"><input id="tbxTenWiFi" style="margin: auto;"></td>
            </tr>
            <tr>
                <td style="text-align: right; padding: 5px">Mật khẩu:</td>
                <td style="text-align: left; width: 50%" ><input id="tbxMatKhauWiFi" style="margin: auto;"></td>
            </tr>
        </tbody>
    </table>

    <div style="text-align: center; margin-top: 25px">        
        <button class="NutNhan" id="btnQuetTimWiFi" onclick="QuetTimWiFi()">QUÉT WiFi</button>
        <button class="NutNhan" id="btnLuuWiFiVaoEEPROM" onclick="LuuWiFiVaoEEPROM()">LƯU WiFi</button>
    </div>
</div>


<div id="ThongBao" style="text-align: center;"></div>
<section id="DanhSachWiFi" style="text-align: center;"></section>

<script>
</script>

</body>
</html>
)rawliteral";


//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//================================== Begin: STYLE CSS ===============================================//
//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
const char style_css[] PROGMEM = R"rawliteral(
body {
  background-color: #FFF;
  border: 0;
  margin: 0;
  font: 1em tahoma, arial, sans-serif;
}  
header {
  border-bottom: 1px solid #888;
  padding: 10px;
}
section {
  padding-top: 5px;
  border-bottom: 1px solid #888;
  border-top: 1px solid #888;
}
#ThongBao {
  border-top: 1px solid #888;
  text-align: left; 
  padding: 5px 0 5px 15px;
  font: 0.9em tahoma, arial, sans-serif;
  font-style: italic;
}
h1 {
color: #F07057;
}      
.NutNhan {
  height: 30px; 
  width: 130px; 
  margin: 10px 0;
  color: #FFFFFF;
  background-color: #F07057;
  border-radius: 3px;
  border: 1px solid #EEE;
}
.ape {
  margin-left: 15px;
  padding: 3px 0px;
  font: 0.9em tahoma, arial, sans-serif;
}
.ape:hover {
  cursor: pointer;
}
.w0 {
  background: url('data:image/svg+xml;base64,PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0iVVRGLTgiIHN0YW5kYWxvbmU9Im5vIj8+CjwhRE9DVFlQRSBzdmcgUFVCTElDICItLy9XM0MvL0RURCBTVkcgMS4xLy9FTiIgImh0dHA6Ly93d3cudzMub3JnL0dyYXBoaWNzL1NWRy8xLjEvRFREL3N2ZzExLmR0ZCI+Cjxzdmcgd2lkdGg9IjI0IiBoZWlnaHQ9IjI0IiB2ZXJzaW9uPSIxLjEiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgeG1sOnNwYWNlPSJwcmVzZXJ2ZSI+CjxwYXRoIGQ9Ik0xLDlMMywxMUM3Ljk3LDYuMDMgMTYuMDMsNi4wMyAyMSwxMUwyMyw5QzE2LjkzLDIuOTMgNy4wOCwyLjkzIDEsOVoiIHN0eWxlPSJmaWxsOiBibGFjazsiLz4KPHBhdGggZD0iTTUsMTNMNywxNUM5Ljc2LDEyLjI0IDE0LjI0LDEyLjI0IDE3LDE1TDE5LDEzQzE1LjE0LDkuMTQgOC44Nyw5LjE0IDUsMTNaIiBzdHlsZT0iZmlsbDogYmxhY2s7Ii8+CjxwYXRoIGQ9Ik05LDE3TDEyLDIwTDE1LDE3QzEzLjM1LDE1LjM0IDEwLjY2LDE1LjM0IDksMTdaIiBzdHlsZT0iZmlsbDogYmxhY2s7Ii8+Cjwvc3ZnPgo=') no-repeat right top;
  height: 24px;
  margin-right: 20px;
}
.w1 {
  background:  url('data:image/svg+xml;base64,PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0iVVRGLTgiIHN0YW5kYWxvbmU9Im5vIj8+CjwhRE9DVFlQRSBzdmcgUFVCTElDICItLy9XM0MvL0RURCBTVkcgMS4xLy9FTiIgImh0dHA6Ly93d3cudzMub3JnL0dyYXBoaWNzL1NWRy8xLjEvRFREL3N2ZzExLmR0ZCI+Cjxzdmcgd2lkdGg9IjI0IiBoZWlnaHQ9IjI0IiB2ZXJzaW9uPSIxLjEiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgeG1sOnNwYWNlPSJwcmVzZXJ2ZSI+CjxwYXRoIGQ9Ik0xLDlMMywxMUM3Ljk3LDYuMDMgMTYuMDMsNi4wMyAyMSwxMUwyMyw5QzE2LjkzLDIuOTMgNy4wOCwyLjkzIDEsOVoiIHN0eWxlPSJmaWxsOiBncmF5OyIvPgo8cGF0aCBkPSJNNSwxM0w3LDE1QzkuNzYsMTIuMjQgMTQuMjQsMTIuMjQgMTcsMTVMMTksMTNDMTUuMTQsOS4xNCA4Ljg3LDkuMTQgNSwxM1oiIHN0eWxlPSJmaWxsOiBibGFjazsiLz4KPHBhdGggZD0iTTksMTdMMTIsMjBMMTUsMTdDMTMuMzUsMTUuMzQgMTAuNjYsMTUuMzQgOSwxN1oiIHN0eWxlPSJmaWxsOiBibGFjazsiLz4KPC9zdmc+Cg==') no-repeat right top;
  height: 24px;
  margin-right: 20px;
}
.w2 {
  background:  url('data:image/svg+xml;base64,PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0iVVRGLTgiIHN0YW5kYWxvbmU9Im5vIj8+CjwhRE9DVFlQRSBzdmcgUFVCTElDICItLy9XM0MvL0RURCBTVkcgMS4xLy9FTiIgImh0dHA6Ly93d3cudzMub3JnL0dyYXBoaWNzL1NWRy8xLjEvRFREL3N2ZzExLmR0ZCI+Cjxzdmcgd2lkdGg9IjI0IiBoZWlnaHQ9IjI0IiB2ZXJzaW9uPSIxLjEiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgeG1sOnNwYWNlPSJwcmVzZXJ2ZSI+CjxwYXRoIGQ9Ik0xLDlMMywxMUM3Ljk3LDYuMDMgMTYuMDMsNi4wMyAyMSwxMUwyMyw5QzE2LjkzLDIuOTMgNy4wOCwyLjkzIDEsOVoiIHN0eWxlPSJmaWxsOiBncmF5OyIvPgo8cGF0aCBkPSJNNSwxM0w3LDE1QzkuNzYsMTIuMjQgMTQuMjQsMTIuMjQgMTcsMTVMMTksMTNDMTUuMTQsOS4xNCA4Ljg3LDkuMTQgNSwxM1oiIHN0eWxlPSJmaWxsOiBncmF5OyIvPgo8cGF0aCBkPSJNOSwxN0wxMiwyMEwxNSwxN0MxMy4zNSwxNS4zNCAxMC42NiwxNS4zNCA5LDE3WiIgc3R5bGU9ImZpbGw6IGJsYWNrOyIvPgo8L3N2Zz4K') no-repeat right top;
  height: 24px;
  margin-right: 20px;
}
.w3 {
  background:  url('data:image/svg+xml;base64,PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0iVVRGLTgiIHN0YW5kYWxvbmU9Im5vIj8+CjwhRE9DVFlQRSBzdmcgUFVCTElDICItLy9XM0MvL0RURCBTVkcgMS4xLy9FTiIgImh0dHA6Ly93d3cudzMub3JnL0dyYXBoaWNzL1NWRy8xLjEvRFREL3N2ZzExLmR0ZCI+Cjxzdmcgd2lkdGg9IjI0IiBoZWlnaHQ9IjI0IiB2ZXJzaW9uPSIxLjEiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgeG1sOnNwYWNlPSJwcmVzZXJ2ZSI+CjxwYXRoIGQ9Ik0xLDlMMywxMUM3Ljk3LDYuMDMgMTYuMDMsNi4wMyAyMSwxMUwyMyw5QzE2LjkzLDIuOTMgNy4wOCwyLjkzIDEsOVoiIHN0eWxlPSJmaWxsOiBncmF5OyIvPgo8cGF0aCBkPSJNNSwxM0w3LDE1QzkuNzYsMTIuMjQgMTQuMjQsMTIuMjQgMTcsMTVMMTksMTNDMTUuMTQsOS4xNCA4Ljg3LDkuMTQgNSwxM1oiIHN0eWxlPSJmaWxsOiBncmF5OyIvPgo8cGF0aCBkPSJNOSwxN0wxMiwyMEwxNSwxN0MxMy4zNSwxNS4zNCAxMC42NiwxNS4zNCA5LDE3WiIgc3R5bGU9ImZpbGw6IGdyYXk7Ii8+Cjwvc3ZnPgo=') no-repeat right top;
  height: 24px;
  margin-right: 20px;
}
)rawliteral";
//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//================================== Begin: STYLE CSS ===============================================//
//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM


//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//================================== Begin: CODE JAVASCRIPT =========================================//
//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
const char code_js[] PROGMEM = R"rawliteral(

const gel = (e) => document.getElementById(e);

function create_obj() {
    td = navigator.appName;
    if(td == "Microsoft Internet Explorer") {
        obj = new ActiveXObject("Microsoft.XMLHTTP");
    }
    else {
        obj = new XMLHttpRequest();
    }
    
    return obj;
}
var xhttp = create_obj();
//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
async function LuuWiFiVaoEEPROM() {
    var TenWiFi = document.getElementById("tbxTenWiFi").value;
    var MatKhauWiFi = document.getElementById("tbxMatKhauWiFi").value;
    xhttp.open("GET","/LuuWiFiVaoEEPROM?TenWiFi=" + TenWiFi + "&MatKhauWiFi=" + MatKhauWiFi, true);
    xhttp.onreadystatechange = KetQuaLuuWiFi;//nhận reponse 
    xhttp.send();
}
//--------------------------------Kiểm tra response -------------------------------------------------//
function KetQuaLuuWiFi(){
  if(xhttp.readyState == 4 && xhttp.status == 200){        
      //---------- Update data sử dụng javascript ----------//
      var res = xhttp.responseText;    
      gel("ThongBao").innerHTML = res;     
  }
}
//-----------------------------------------------------------------------------------------------------
async function QuetTimWiFi() {
    gel("ThongBao").innerHTML = "Đang quét tìm WiFi (15-30s)...";
    xhttp.open("GET","/QuetTimWiFi", true);
    xhttp.onreadystatechange = KetQuaQuetTimWiFi;//nhận reponse 
    xhttp.send();
}
//---------------------------------------------------------------------------------------------------//
//--------------------------------Kiểm tra response -------------------------------------------------//
function KetQuaQuetTimWiFi(){
  if(xhttp.readyState == 4 && xhttp.status == 200){        
      //---------- Update data sử dụng javascript ----------//
      var res = xhttp.responseText;    
      gel("DanhSachWiFi").innerHTML = res;     
  }
}
//-----------------------------------------------------------------------------------------------------
gel("DanhSachWiFi").addEventListener(
  "click",
  (e) => {
    gel("tbxTenWiFi").value = e.target.innerText;
  },
  false
);
//-----------------------------------------------------------------------------------------------------
)rawliteral";
//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//================================== End: CODE JAVASCRIPT ===========================================//
//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM

#endif