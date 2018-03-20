# Islandora Dimensions

## Introduction

Islandora Dimensions provides a Dimensions badge for objects with DOIs allowing users to easily see how many citations a publication has received. For use with Islandora Badges.

This modules uses the [Dimensions API](https://badge.dimensions.ai/). Before using this module one should familiarize oneself with the [terms of use](https://dimensions.ai/policies/terms/metrics).

## Requirements

This module requires the following modules/libraries:

* [Islandora](https://github.com/islandora/islandora)
* [Islandora Scholar](https://github.com/Islandora/islandora_scholar)
* [Islandora Badges](../../)

## Installation

Install as usual, see [this](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

## Configuration

Configuration path is admin/islandora/tools/badges/dimensions (Administration > Islandora > Islandora Utility Modules > Islandora Badges Configuration > Dimensions).

There are two administration options:

* Dimensions Badge
     * provide one of the [badge styles](https://badge.dimensions.ai/#styles) defined by Dimensions.
* Dimensions Legend
     * defines the location where the [legend displays](https://badge.dimensions.ai/#legend).

The module provides a block, Islandora Dimensions, that can be placed in a block region.

Once enabled the badge is displayed on objects that have a DOI as configured and some metrics.  If it has a DOI but does not display,  the article does not currently have any metrics.

## Documentation

Further documentation for this module is available at [our wiki](https://wiki.duraspace.org/x/bhpsBQ).

## Troubleshooting/Issues

Having problems or solved a problem? Check out the Islandora google groups for a solution.

* [Islandora Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora)
* [Islandora Dev Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora-dev)

## Maintainers/Sponsors

Current maintainers:

* [William Panting](https://github.com/willtp87)
* [Brandon Weigel](https://github.com/bondjimbond)

## Development

If you would like to contribute to this module, please check out [CONTRIBUTING.md](CONTRIBUTING.md). In addition, we have helpful [Documentation for Developers](https://github.com/Islandora/islandora/wiki#wiki-documentation-for-developers) info, as well as our [Developers](http://islandora.ca/developers) section on the [Islandora.ca](http://islandora.ca) site.

## Notes

Used Islandora Altmetrics as the pattern for this module.
## License

[GPLv3](http://www.gnu.org/licenses/gpl-3.0.txt)
