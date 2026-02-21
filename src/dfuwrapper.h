/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (C) 2024 Raspberry Pi Ltd
 */

#ifndef DFUWRAPPER_H
#define DFUWRAPPER_H

#include <QString>
#include <QObject>

struct dfu_if;
struct libusb_context;

class DfuWrapper : public QObject
{
    Q_OBJECT

public:
    static constexpr int TI_VENDOR_ID  = 0x0451;
    static constexpr int TI_PRODUCT_ID = 0x6165;

    static constexpr const char* ALT_BOOTLOADER = "bootloader";
    static constexpr const char* ALT_TISPL      = "tispl.bin";
    static constexpr const char* ALT_UBOOT      = "u-boot.img";
    static constexpr const char* ALT_RAWEMMC    = "rawemmc";

    explicit DfuWrapper(QObject *parent = nullptr);
    ~DfuWrapper();

    bool initialize();
    bool findDevice(int vendorId, int productId, const QString &altSettingName);
    bool downloadFile(const QString &filePath, bool resetAfter = true);
    bool downloadFileStreaming(const QString &filePath);

    QString lastError() const { return _lastError; }
    void cleanup();

signals:
    void statusMessage(QString message);

private:
    struct libusb_context *usbContext;
    struct dfu_if *dfuDevice;
    bool initialized;
    QString _lastError;
    QByteArray _altNameBytes;

    int  getTransferSize();
    void setError(const QString &msg);
    bool claimInterface();
};

#endif // DFUWRAPPER_H
